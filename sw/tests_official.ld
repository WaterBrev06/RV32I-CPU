OUTPUT_ARCH(riscv)
ENTRY(_start)
SECTIONS {
  . = 0x0;
  .text : { *(.text.init) *(.text*) }
  . = 0x2000;
  .data : { *(.data*) *(.sdata*) *(.rodata*) *(.srodata*) *(.bss*) *(.sbss*) }
  . = 0x3000;
  .tohost : { *(.tohost) }
  ASSERT(SIZEOF(.text) <= 0x2000, "code does not fit below the data region")
  ASSERT(SIZEOF(.data) <= 0x1000, "test data overlaps tohost")
  /DISCARD/ : { *(.comment) *(.riscv.attributes) *(.note*) }
}
