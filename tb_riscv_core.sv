`timescale 1ns / 1ps

module tb_riscv_core;

    // Testbench signals
    logic        clk;
    logic        rst;
    logic [31:0] wb_result;

    int error_count = 0;
    int test_count  = 0;

    // Instantiate Unit Under Test (UUT)
    riscv_core uut (
        .clk       (clk),
        .rst       (rst),
        .wb_result (wb_result)
    );

    // Clock Generation: 50 MHz (20ns period)
    always #10 clk = ~clk;

    // Task for assertions on internal Register File values
    task automatic check_reg(
        input logic [4:0]  reg_addr,
        input logic [31:0] expected_val,
        input string       test_desc
    );
        test_count++;
        if (uut.rf.rf[reg_addr] !== expected_val) begin
            $display("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)",
                     test_desc, reg_addr, uut.rf.rf[reg_addr], uut.rf.rf[reg_addr], expected_val, expected_val);
            error_count++;
        end else begin
            $display("PASS [%s]: x%0d = 0x%h (%0d)", 
                     test_desc, reg_addr, uut.rf.rf[reg_addr], uut.rf.rf[reg_addr]);
        end
    endtask

    // Task for assertions on Data Memory values
    task automatic check_mem(
        input logic [31:0] mem_addr,
        input logic [31:0] expected_val,
        input string       test_desc
    );
        test_count++;
        if (uut.dmem.mem[mem_addr[9:2]] !== expected_val) begin
            $display("FAIL [%s]: Mem[0x%h] = 0x%h, Expected = 0x%h",
                     test_desc, mem_addr, uut.dmem.mem[mem_addr[9:2]], expected_val);
            error_count++;
        end else begin
            $display("PASS [%s]: Mem[0x%h] = 0x%h", 
                     test_desc, mem_addr, uut.dmem.mem[mem_addr[9:2]]);
        end
    endtask

    initial begin
        // Initialize signals
        clk = 0;
        rst = 1;

        $display("==================================================");
        $display(" STARTING RISC-V TOP-LEVEL END-TO-END CORE TEST   ");
        $display("==================================================");

        // Apply Reset for 2 clock cycles
        #20;
        rst = 0;

        // Allow 15 clock cycles (300ns) for the test program to cycle through all 5 pipeline stages
        // Executing pre-loaded program in instr_mem:
        // [0] addi x1, x0, 10   (x1 <= 10)
        // [1] addi x2, x0, 20   (x2 <= 20)
        // [2] add  x3, x1, x2   (x3 <= 30, relies on EX-to-EX forwarding)
        // [3] sw   x3, 0(x0)    (mem[0] <= 30)
        // [4] lw   x4, 0(x0)    (x4 <= 30, tests MEM-to-EX/WB datapath)
        #300;

        $display("\n--------------------------------------------------");
        $display(" VERIFYING PIPELINE EXECUTION & HAZARD RESOLUTION ");
        $display("--------------------------------------------------");

        // 1. Verify Immediate Addition (addi x1, x0, 10)
        check_reg(5'd1, 32'd10, "1. Immediate Addition into x1");

        // 2. Verify Second Immediate Addition (addi x2, x0, 20)
        check_reg(5'd2, 32'd20, "2. Immediate Addition into x2");

        // 3. Verify Forwarded R-Type ADD (add x3, x1, x2)
        check_reg(5'd3, 32'd30, "3. RAW Hazard Forwarded Addition into x3");

        // 4. Verify Store Word (sw x3, 0(x0))
        check_mem(32'd0, 32'd30, "4. Store Word to Data Memory Addr 0x0");

        // 5. Verify Load Word (lw x4, 0(x0))
        check_reg(5'd4, 32'd30, "5. Load Word from Data Memory into x4");

        // Verification Summary
        $display("==================================================");
        if (error_count == 0) begin
            $display("SUCCESS: All %0d end-to-end integration tests passed!", test_count);
        end else begin
            $display("FAILURE: %0d out of %0d tests failed.", error_count, test_count);
        end
        $display("==================================================");

        $finish;
    end

endmodule