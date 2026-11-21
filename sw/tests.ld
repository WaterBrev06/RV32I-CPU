OUTPUT_ARCH(riscv)
ENTRY(_start)
SECTIONS {
  . = 0x0;
  .text : { *(.text.init) *(.text*) }
  . = 0x2000;
  .data : { *(.data*) *(.sdata*) *(.rodata*) *(.srodata*) *(.bss*) *(.sbss*) }
  ASSERT(SIZEOF(.text) <= 0x2000, "code does not fit below the data region")
  /DISCARD/ : { *(.comment) *(.riscv.attributes) *(.note*) }
}
