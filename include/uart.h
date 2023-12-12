#ifndef _UART_H
#define _UART_H
#include<stdio.h>
#include<stdint.h>

extern void uart_init();
extern void uart_send(uint8_t data);
extern uint8_t uart_recv();
extern void uart_test();
extern void uart_puts(const char *str);

extern int uart_printf(const char *fmt, ...);
extern void uart_printf_test(void);
#endif