#ifndef _ADC_H
#define _ADC_H
void adc_init();
int adc_auto_calibration();
void adc_channel_start(int channel);
int adc_interrupt_handler(int id);
void adc_test();
#endif