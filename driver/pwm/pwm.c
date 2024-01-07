#include"imx6ull.h"
#include"pwm.h"
#include"gpt.h"

void pwm_init(uint32_t period, uint32_t sample) {
    /* 1. Enable Clock:GPIO,PWM */
    CCM_CCGR1 |= (0x3 << 26);
    CCM_CCGR4 |= (0x3 << 18);

    /* 2. GPIO MODE: PWM */
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO09 &= ~(0xf << 0);

    /* 3. Reset PWM */
    PWM2->PWMCR |= (1 << 3);
    while(PWM2->PWMCR & (1 << 3)){}

    /* 4. Select Clock:IPG_CLK / pre
                       = 66MHZ / (65 + 1) = 1MHZ
     */
    PWM2->PWMCR = (1 << 16) | (65 <= 4);

    /* 5. set PWM Period,PWM Sample */
    PWM2->PWMPR = period - 2;
    PWM2->PWMSAR = sample;
}

/* 6.start and stop PWM */
void pwm_start() {
    PWM2->PWMCR |= (1 << 0);
}

void pwm_stop() {
    PWM2->PWMCR &= ~(1 << 0);
}

void pwm_test() {
    pwm_init(1000, 500);

    pwm_start();

    // sample数值写进FIFO缓存中，每次最多写4个，比较4次就清空了
    // 需要不断向FIFO中写sanple值，保证PWM波不断输出
    int i;
    for(i = 0; i < 100; i++) {
        set_sample_value(i * 10);
        gpt_delay_ms(500);
    }

    pwm_stop();
}

void set_sample_value(uint32_t val) {
    PWM2->PWMSAR = val;
}
