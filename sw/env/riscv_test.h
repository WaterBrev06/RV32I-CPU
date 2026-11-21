#ifndef _ENV_RV32I_CPU_H
#define _ENV_RV32I_CPU_H

#define RVTEST_RV32U
#define RVTEST_RV64U
#define TESTNUM gp

#define RVTEST_CODE_BEGIN   .section .text.init; .align 2; .globl _start; _start: li TESTNUM, 0;
#define RVTEST_CODE_END     2: j 2b;

/* pass: result = 1. fail: result = number of the failing test case. Then set the done flag. */
#define RVTEST_PASS  li t0, 0x3F8; li t1, 1; sw t1, 0(t0); sw t1, 4(t0); 1: j 1b;
#define RVTEST_FAIL  li t0, 0x3F8; sw TESTNUM, 0(t0); li t1, 1; sw t1, 4(t0); 1: j 1b;

#define EXTRA_DATA
#define RVTEST_DATA_BEGIN   EXTRA_DATA .align 4; .global begin_signature; begin_signature:
#define RVTEST_DATA_END     .align 4; .global end_signature; end_signature:
#endif
