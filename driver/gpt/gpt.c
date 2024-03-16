#include"imx6ull.h"
#include"led.h"
#include"gpt.h"

void gpt_init() {
    /* 1.Reset GPT */
    GPT1->CR |= (1 << 15);
    while(GPT1->CR & (1 << 15)){}

    /* 2.Select Clock:IPG(66MHZ) */
    GPT1->CR &= ~(0x7 << 6);
    GPT1->CR |=  (0x1 << 6);

    /* 3.Select mode :Free-Run or Restart */
    GPT1->CR |= (1 << 9); // Free-Run

    /* 4.Select Prescaler:65:1MHZ-->1us 增加一次*/
    GPT1->PR = 65;
}

void gpt_delay_us(uint32_t us) {
    gpt_init();
    /* 5.GPT Output Compare value:depandens delay time*/
    GPT1->OCR1 = us;

    /* 6.start gpt */
    gpt_start();
    /* 7.wait output compare event occur */
    wait_cmp_event();
    /* 8.stop gpt */
    gpt_stop();
}
void gpt_delay_ms(uint32_t ms) {
    gpt_delay_us(ms * 1000);
}
void gpt_delay_sec(uint32_t sec) {
    gpt_delay_ms(sec * 1000);
}
void gpt_start() {
    // 设置ENMOD为1时，GPT counter value is reset to 0 when it is disabled
    GPT1->CR |= (1 << 0) | (1 << 1); 
}

void gpt_stop() {
    GPT1->CR &= ~(1 << 0); // 使能位，不是1位
}

void wait_cmp_event() {
    int flag = 0;
    while(!flag) {
        flag = GPT1->SR & (1 << 0);
    }
}

void gpt_test() {
    led_init();

    while(1) {
        led_on();
        gpt_delay_ms(500);

        led_off();
        gpt_delay_ms(500);
    }
}
