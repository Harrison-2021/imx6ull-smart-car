#include"imx6ull.h"
#include"wdt.h"
#include"gpt.h"
#include"uart.h"

void wdt_init() {
    /*Enable WDT Clock*/
    CCM_CCGR3 |= (0x3 << 16);
    
    /*wdt reset signal to cold reset*/
    SRC->SCR &= ~(1 << 0);

    /*
      WDE [2] 0 Disable the Watchdog (Default)
    */
    WDOG1->WCR &= ~(1 << 2);

    /*
      Wdt Timer 5s timeout
      WT [15:8] Watchdog Time-out Field.  
    */
    WDOG1->WCR &= ~(0xff << 8);
    WDOG1->WCR |= (0x9 << 8);

    /*
      WDE [2] 1 Enable the Watchdog.
    */
    WDOG1->WCR |= (1 << 2);
}

void wdt_refresh() {
    WDOG1->WSR = 0x5555;
    WDOG1->WSR = 0xAAAA;
    
}

void wdt_test() {
    int i;

    uart_printf("wdt test ...\r\n");
    wdt_init();

    // 延时3秒启动开门狗
    uart_printf("Delay 3 second\r\n");
    gpt_delay_sec(3);
    wdt_refresh();
    uart_printf("WDT Refresh Done\r\n");

    // 10秒内不进行喂狗，观察是否重启
    for(i = 0;i < 10;i ++){
        uart_printf("Wait reset %d\r\n",i);
        gpt_delay_sec(1);
    }
}
