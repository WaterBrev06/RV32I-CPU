OUTPUT_ARCH(riscv)
ENTRY(_start)
SECTIONS {
  . = 0x0;
  .text : { *(.text.init) *(.text*) }
  .data : { *(.data*) *(.sdata*) *(.rodata*) *(.srodata*) *(.bss*) *(.sbss*) }
  ASSERT(SIZEOF(.data) == 0, "No global/static data: imem and dmem are separate")
  /DISCARD/ : { *(.comment) *(.riscv.attributes) *(.note*) *(.eh_frame*) }
}
