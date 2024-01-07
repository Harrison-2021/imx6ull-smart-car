#include"imx6ull.h"
#include"led.h"
#include"key.h"
#include"uart.h"
#include"interrupt.h"

void key_init() {
    /* 1.GPIO Mode */
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO26 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO26 |=  (0x5 << 0);

    /* 2.Direction:Input */
    GPIO1->GDIR &= ~(1 << 26);

    /* 3.Enable GPIO Clock */
    CCM_CCGR1 |= (0x3 << 26);
}

/* 4.GPIO pad status */
int is_key_press() {
    int level = GPIO1->PSR & (1 << 26);
    return level == 0 ? 1 : 0; // 被按下，上拉电阻为低电平
}

void key_test() {
    key_init();
    led_init(); // led灯也要初始化

    while(1) {
        if(is_key_press()) led_on();
        else led_off();
    }
} 

/* key interrupt event function*/
int key_interrupt_handler(int id) {
    uart_printf("key press, irq number:%d\r\n",id);

    /*Clear GPIO1_26 Interrupt Statu*/
    GPIO1->ISR |= (1 << 26);
}

void key_gpio_interrupt_init(void) {
    /* 1.GPIO Mode */
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO26 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO26 |=  (0x5 << 0);

    /*2. interrupt trigger level:low*/
    GPIO1->ICR2 &= ~(0x3 << 20);

    /*3. Enable GPIO1_26 Interrupt*/
    GPIO1->IMR |= (1 << 26);

    /*4.Clear GPIO1_26 Interrupt Statu*/
    GPIO1->ISR |= (1 << 26);
}

void key_interrupt_test(void) {
    key_gpio_interrupt_init();
    request_irq(GPIO1_Combined_16_31_IRQn,key_interrupt_handler);
    enable_irq(); // ARM使能，CPSR第7位写1，执行IRQ异常处理，从而执行中断函数
}