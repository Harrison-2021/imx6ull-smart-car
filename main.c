#include"imx6ull.h"
#include"led.h"
#include"gpt.h"
#include"pwm.h"
#include"uart.h"
#include"key.h"
int main()
{
	key_interrupt_test();
	led_test();
	return 0;
}
