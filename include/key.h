#ifndef _KEY_H
#define _KEY_H

extern void key_test();
extern void key_init();
extern int is_key_press();
int key_interrupt_handler(int id);
void key_gpio_interrupt_init(void);
void key_interrupt_test(void);
#endif