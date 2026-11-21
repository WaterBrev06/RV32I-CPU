.section .text.init
.globl _start
_start:
    li   sp, 0x3F0          # stack grows down from near the top of the 1 KB data memory
    call main               # becomes AUIPC + JALR (or JAL): both work now
    li   t0, 0x3F8
    sw   a0, 0(t0)          # main's return value -> data memory 0x3F8
    li   t1, 1
    sw   t1, 4(t0)          # done flag -> 0x3FC
1:  j    1b                 # spin forever
