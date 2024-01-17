#include"imx6ull.h"
#include"led.h"
#include"gpt.h"
#include"pwm.h"
#include"uart.h"
#include"key.h"
#include"adc.h"
#include"wdt.h"
#include"rtc.h"

int main()
{
	rtc_test();
	return 0;
}
