#ifndef _RTC_H
#define _RTC_H
#include"datetime.h"

void rtc_init();
void rtc_stop();
void rtc_start();
void rtc_set_datetime(const rtc_datetime_t *datetime);
void rtc_get_datetime(rtc_datetime_t *datetime);
void rtc_test(void);
void rtc_set_alarm(rtc_datetime_t* datetime);
int rtc_interrupt_handler(int id);
#endif