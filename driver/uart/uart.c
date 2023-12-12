#include"imx6ull.h"
#include"uart.h"

void uart_init() {
    /* 1. Enable UART1 Clock */
    CCM_CCGR5 |= (0x3 << 24);

    /* 2. GPIO MODE: UART1 */
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO16 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO17 &= ~(0xf << 0);

    /* 3. Set UART1
        8bit data,1bit stop,no even/odd,115200 bit/s
     */
    UART1->UCR2 = (1 << 14) | (1 << 5) | (1 << 2)
        | (1 << 1); // UCR2,寄存器不要选错了
    UART1->UCR3 |= (1 << 2);
    UART1->UFCR = (0x5 << 7); // clk:80MHZ
    UART1->UBIR = 9;
    UART1->UBMR = 433;

    /* 4. Enable UART */
    UART1->UCR1 |= (1 << 0);
}

/* 5. send,receive */
void uart_send(uint8_t data) {
    int flag = 0;

    UART1->UTXD = data;
    // wait transmit complete
    while(!flag) {
        flag = UART1->USR2 & (1 << 3);
    }
}

uint8_t uart_recv() {
    int flag = 0;

    // wait data read
    while(!flag) {
        flag = UART1->USR2 & (1 << 0);
    }
    return UART1->URXD & 0xff;
}

void uart_test() {
    uint8_t data;
    uart_init();

    // 测试从控制板写入数据，向pc端发送数据，pc端接收并通过kermit传递显示
    uart_puts("hello imx6ull\r\n");
    uart_puts("hello uart\r\n");

    // 测试从pc端发送数据，控制板接收，并转发至pc端
    while(1) {
        data = uart_recv();
        uart_send(data);
    }
}

void uart_puts(const char *str) {
    const char *p = NULL;

    uart_init();
    
    for(p = str; *p; p++) {
        uart_send(*p);
    }
}