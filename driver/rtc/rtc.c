#include"imx6ull.h"
#include"rtc.h"
#include"interrupt.h"

void rtc_init() {
    /*Enable Clock*/
    CCM_CCGR5 |= (0x3 << 18);

    /*
    NPSWA_EN [31] 1 Any software can access privileged registers
    */
    SNVS->HPCOMR |= (1 << 31);

    return;
}

void rtc_stop() {
    /*
        RTC_EN [0] 0b  clear Enable
    */
    SNVS->HPCR &= ~(1 << 0);
    while(SNVS->HPCR & (1 << 0)){}
}

void rtc_start() {
    /*
        RTC_EN [0] 1b  Enable
    */
    SNVS->HPCR |= (1 << 0);
    while(SNVS->HPCR & (1 << 0) == 0){}

}

void rtc_set_datetime(const rtc_datetime_t *datetime) {
    uint32_t seconds;
	// 先停止RTC计数器，将时间结构体转为秒
    rtc_stop();
    seconds = convert_datetime_to_seconds(datetime);// 传递指针或结构体地址
	// 储存于寄存器中，寄存器分为高低地址，分别储存second的高15位，低17位
    //高15bit
    SNVS->HPRTCMR |= (seconds >> 17);
    //[31:18][17:0]
    //低17位
    SNVS->HPRTCLR |= (seconds << 15);
	// 开启RTC计数器
    rtc_start();

}

void rtc_get_datetime(rtc_datetime_t *datetime) {
   uint32_t tmp = 0;
   uint32_t seconds = 0;
   // 读取两次，进行比对，防止一次读取不准确
   do {
        tmp = seconds;
        seconds = (SNVS->HPRTCMR << 17) | (SNVS->HPRTCLR >> 15);
   } while(tmp != seconds);
   // 将读取的时间秒，转换为时间结构体进行储存
   convert_seconds_to_datetime(seconds, datetime);

}

void rtc_set_alarm(rtc_datetime_t* datetime) {
    int seconds;

    uart_printf("RTC Alarm datetime  %d-%d-%d  %d:%d:%d\r\n",
        datetime->year,datetime->month,datetime->day,
        datetime->hour,datetime->minute,datetime->second);
    
    //request rtc interrupt
    request_irq(SNVS_Consolidated_IRQn,rtc_interrupt_handler);
    enable_irq();
    
    //disable alarm
    SNVS->HPCR &= ~(1 << 1);
    while(SNVS->HPCR & (1 << 1)){}
    
    //set alarm datetime
    seconds = convert_datetime_to_seconds(datetime);
    SNVS->HPTAMR |= (seconds >> 17);
    SNVS->HPTALR |= (seconds << 15);

    //Enable alarm
    SNVS->HPCR |= (1 << 1);
    while(SNVS->HPCR & (1 << 1) == 0) {}
}

int rtc_interrupt_handler(int id) {
    if(SNVS->HPSR & (1 << 0)) {
        uart_printf("RTC Alarm interrupt ok!\r\n");
        // clear alarm interrupt pending
        SNVS->HPSR |= (1 << 0); // 写1清0
        while(SNVS->HPSR & (1 << 0)) {}

    }
    return 0;
}

void rtc_test(void) {
    rtc_datetime_t datetime;
    rtc_datetime_t alarm_datetime;
    rtc_init();

    datetime.year   = 2023;
    datetime.month  = 1;
    datetime.day    = 1;
    datetime.hour   = 21;
    datetime.minute = 40;
    datetime.second = 30;

    rtc_set_datetime(&datetime);

    alarm_datetime.year   = 2023;
    alarm_datetime.month  = 1;
    alarm_datetime.day    = 1;
    alarm_datetime.hour   = 21;
    alarm_datetime.minute = 40;
    alarm_datetime.second = 35;
    rtc_set_alarm(&alarm_datetime);

    while(1){
        rtc_get_datetime(&datetime);

        uart_printf("%d-%d-%d  %d:%d:%d\r\n",datetime.year,datetime.month,datetime.day,
        datetime.hour,datetime.minute,datetime.second);

        gpt_delay_sec(1);
    }
}