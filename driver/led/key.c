#include"imx6ull.h"
#include"led.h"

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