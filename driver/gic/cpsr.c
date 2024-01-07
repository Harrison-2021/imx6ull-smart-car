#include "interrupt.h"
int enable_irq(void)
{
    int status;

    asm(
        "mrs r0,cpsr\n"
        "mov r1,#1\n"
        "bic r0,r0,r1,lsl #7\n"
        "msr cpsr,r0\n"
        "mov %0,r0\n"
        :"=r"(status)
        :
        :"r0","r1"
    );

    return status;
}

int disable_irq(void)
{
    int status;

    asm(
        "mrs r0,cpsr\n"
        "mov r1,#1\n"
        "orr r0,r0,r1,lsl #7\n"
        "msr cpsr,r0\n"
        "mov %0,r0\n"
        :"=r"(status)
        :
        :"r0","r1"
    );

    return status;
}