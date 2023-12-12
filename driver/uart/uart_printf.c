#include<stdarg.h>
#include"uart.h"
#include<stdio.h>

int uart_printf(const char *fmt, ...) {
    va_list args;
    char printbuffer[1024];

    va_start(args,fmt);
    vsprintf(printbuffer,fmt,args);
    va_end(args);

    uart_puts(printbuffer);
}

void uart_printf_test(void) {
    uint32_t data = 100;
    const char *str = "hello uart printf";

    uart_printf("data = %d\r\n", data);
    uart_printf("str = %s\r\n",str);
    uart_printf("data = %#x\r\n",data);
}