#ifndef _GPT_H
#define _GPT_H

extern void gpt_test();
extern void gpt_init();
extern void gpt_init();
extern void gpt_delay_us(uint32_t us);
extern void gpt_delay_ms(uint32_t ms);
extern void gpt_delay_sec(uint32_t sec);
extern void gpt_start();
extern void gpt_stop();
extern void wait_cmp_event();
#endif