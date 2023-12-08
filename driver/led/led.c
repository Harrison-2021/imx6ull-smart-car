#include"imx6ull.h"
#include"led.h"

void led_init(void) {
    /* 1.GPIO MODE */
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO27 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO27 |=  (0x5 << 0);

    /* 2.Direction:Output */
    GPIO1->GDIR |= (1 << 27);

    /* 3.Enable GPIO Clock */
    CCM_CCGR1 |= (0x3 << 26);
}

void led_on(void) {
    /* 4.1 Outpur high level */
    GPIO1->DR |= (1 << 27);
}

void led_off(void) {
    /* 4.2 Output low level */
    GPIO1->DR &= ~(1 << 27);
}

void delay_time(uint32_t time) {
    for(int i = 0; i < 1000*time; i++) {
        for(int j = 0; j < 50000; j++){}
    }
}

void led_test(void) {
    led_init(); // 一定要注意()不要忘记写了
    
    while(1) {
        led_on();
        delay_time(1);
        led_off();
        delay_time(1);
    }

}


