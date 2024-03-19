#include"imx6ull.h"
#include"led.h"
#include"gpt.h"
#include"pwm.h"
#include"uart.h"
#include"key.h"
#include"adc.h"
#include"wdt.h"
#include"rtc.h"
#include"iic.h"
#include"spi.h"
#include"onewire.h"
#include"flexcan.h"
#include"lcd.h"
// void lcd_rgb888_test(void);

int main() {
	lcd_rgb888_test();
	// flexcan_normal_test();
	// flexcan_loopback_test();
	//ds18b20_test();
	// spi_test();
	// hardware_iic_test();
	return 0;
}
