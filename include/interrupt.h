#ifndef _INTERRUPT_H
#define _INTERRUPT_H
typedef unsigned int uint32_t;
typedef int (*handle_t)(int id); // 函数指针

extern void request_irq(int irq_num, handle_t handler);
extern void do_irq(void);
extern int enable_irq(void);
extern int disable_irq(void);
#endif