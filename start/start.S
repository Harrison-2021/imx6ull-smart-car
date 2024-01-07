.global _start

_start:
    b reset
	ldr pc,_undefined_instruction
	ldr pc,_software_interrupt  @B   software_interrupt
	ldr pc,_prefetch_abort
	ldr pc,_data_abort
	ldr pc,_not_used
	ldr pc,_irq
	ldr pc,_fiq
_undefined_instruction:.word _undefined_instruction
_software_interrupt:.word software_interrupt
_prefetch_abort:.word _prefetch_abort
_data_abort:.word _data_abort
_not_used:.word _not_used
_irq:.word irq
_fiq:.word _fiq

reset:
    @告诉ARM核异常向量表所在的基地址
	adr r0,_start @获得异常向量表所在的地址
	mcr p15,0,r0,c12, c0, 0 @将异常向量表的基基地址写入cp15.c12

    ldr sp,=0x87800000
    bl  main

stop:
    b stop

software_interrupt:
	ldr sp,=0x81000000
	stmfd sp!,{r0-r12,lr}

	ldr r0,[lr,#-4]
	mov r1,#0xff
	bic r0,r0,r1,lsl #24

	ldmfd sp!,{r0-r12,pc}^

irq:
	ldr sp,=0x82000000
	sub lr,lr,#4
	stmfd sp!,{r0-r12,lr}

	bl do_irq @处理中断函数

	ldmfd sp!,{r0-r12,pc}^

