#include"imx6ull.h"
#include"led.h"
#include"gpt.h"
#include"pwm.h"
#include"uart.h"
#include"key.h"
#include"adc.h"
#include"wdt.h"

int main()
{
	wdt_test();
	return 0;
}
