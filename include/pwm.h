#ifndef _PWM_H
#define _PWM_h
extern void pwm_init();
extern void pwm_start();
extern void pwm_stop();
extern void pwm_test();
extern void set_sample_value(uint32_t val);
#endif