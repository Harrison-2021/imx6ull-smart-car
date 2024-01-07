#include "interrupt.h"
#include "imx6ull.h"

//用来记录，每个中断源对应的中断处理函数入口地址
handle_t function_table[NUMBER_OF_INT_VECTORS];

//只能向CPU0注册中断
void request_irq(int irq_num, handle_t handler) {
    int index, nbit;
    // 1.GIC Distributer Init
    // 1.1 使能GIC中断分发器转发给CPU接口单元
    GIC->D_CTLR |= (1 << 0);

    //1.2 使能每个中断ID,让中断分发器转发到CPU接口
    index = irq_num >> 5; // index = irq_num/32
    nbit = irq_num - 32 * index; // nbit = irq_num%32
    GIC->D_ISENABLER[index] |= (1 << nbit);

    // 1.3 中断分发器收到中断后，转发给CPU0
    GIC->D_ITARGETSR[irq_num] |= (1 << 0);

    // 1.3 允许任意优先级的中断到达CPU,优先级的值越大，级别越低
    GIC->C_PMR = (0x1f << 3);

    // 2.GIC CPU interface block init
    // 2.1 中断分发器收到中断后，转发给CPU0
    GIC->C_CTLR |= (1 << 0);
    //2.2 记录中断处理函数
    function_table[irq_num] = handler;
}

void do_irq(void) {
    int irq_num;
    handle_t handle;
    // 1.获取中断源信息（id）-注册后记录的中断号
    irq_num = (GIC->C_IAR & 0x3FF);
    // 2.根据中断号获取中断处理函数入口地址-注册后记录的中断函数
    handle = function_table[irq_num];
    // 3.调用中断处理函数
    handle(irq_num);
    // 4.通知中断结束
    GIC->C_EOIR = (GIC->C_EOIR & ~(0x3FF) | irq_num);
}
