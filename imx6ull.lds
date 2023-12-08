OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
 . = 0x00000000;
 . = ALIGN(4);
 .text :
 {
  start/start.o
  *(.text*)
 }
 . = ALIGN(4);
 .rodata : { *(.rodata*) }
 . = ALIGN(4);
 .data : {*(.data*)}
 . = ALIGN(4);
 __bss_start = .;
 .bss ALIGN(4) : { *(.bss)}
 __bss_end = .;

PROVIDE_HIDDEN (__exidx_start = .);
.ARM.exidx   : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) }
PROVIDE_HIDDEN (__exidx_end = .);
}
