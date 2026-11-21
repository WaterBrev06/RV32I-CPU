`timescale 1ns / 1ps

module tb_riscv_core;

    // Testbench signals
    logic        clk;
    logic        rst;
    logic [31:0] wb_result;

    int error_count = 0;
    int test_count  = 0;
    int cycles      = 0;
    int retired     = 0;
    bit done        = 0;
    bit hex_mode    = 0;


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
        if (uut.u_regfile.rf[reg_addr] !== expected_val) begin
            $display("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)",
                     test_desc, reg_addr, uut.u_regfile.rf[reg_addr], uut.u_regfile.rf[reg_addr], expected_val, expected_val);
            error_count++;
        end else begin
            $display("PASS [%s]: x%0d = 0x%h (%0d)", 
                     test_desc, reg_addr, uut.u_regfile.rf[reg_addr], uut.u_regfile.rf[reg_addr]);
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

    always @(posedge clk) begin
        if (!rst && !done) begin
            cycles++;
            if (uut.wb_valid) retired++;
            // stop counting when the end marker (addi x6) completes
            if (!hex_mode && uut.wb_valid && uut.wb_reg_write && uut.wb_rd_addr == 5'd6) done = 1;
            if (hex_mode && uut.dmem.mem[255] == 32'd1) done = 1;
        end
    end

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_riscv_core);
    end
    
    string hexfile;
    int expected;
    int test = 0;
    initial begin
        void'($value$plusargs("TEST=%d", test));

        // Initialize signals
        clk = 0;
        rst = 1;

        $display("==================================================");
        $display(" STARTING RISC-V TOP-LEVEL END-TO-END CORE TEST   ");
        $display("==================================================");

        // Apply Reset for 2 clock cycles
        #20;
        rst = 0;
        if ($value$plusargs("HEX=%s", hexfile)) begin
            hex_mode = 1;
            void'($value$plusargs("EXPECT=%h", expected));
            for (int c = 0; c < 20000 && uut.dmem.mem[255] !== 32'd1; c++) @(posedge clk);
            if (uut.dmem.mem[255] !== 32'd1) begin $display("FAIL: timeout, done flag never set"); error_count++; end
            check_mem(32'h3F8, expected, "C program result");
        end else begin
            #800;

            $display("\n--------------------------------------------------");
            $display(" VERIFYING PIPELINE EXECUTION & HAZARD RESOLUTION ");
            $display("--------------------------------------------------");

            case (test)
                0: begin
                    check_reg(5'd1, 32'd10, "ALU: addi x1");
                    check_reg(5'd2, 32'd20, "ALU: addi x2");
                    check_reg(5'd3, 32'd30, "Forwarding: add x3 = x1 + x2");
                    check_mem(32'd0, 32'd30, "Store: mem[0] = x3");
                    check_reg(5'd4, 32'd30, "Load: x4 = mem[0]");
                end
                1: begin
                    check_reg(5'd3, 32'd0, "BNE taken: x3 skipped");
                    check_reg(5'd4, 32'd0, "BLT taken: x4 skipped");
                    check_reg(5'd5, 32'd1, "BGE not taken: x5 executed");
                    check_reg(5'd8, 32'd0, "BLT signed taken: x8 skipped");
                    check_reg(5'd9, 32'd1, "BLTU not taken: x9 executed");
                end
                2: begin
                    check_reg(5'd3,  32'd0,  "JAL: x3 skipped");
                    check_reg(5'd4,  32'd0,  "JAL: x4 skipped");
                    check_reg(5'd5,  32'd1,  "JAL target executed");
                    check_reg(5'd10, 32'd8,  "JAL link: x10 = PC+4");
                    check_reg(5'd8,  32'd0,  "JALR: x8 skipped");
                    check_reg(5'd12, 32'd28, "JALR link: x12 = PC+4");
                    check_reg(5'd9,  32'd36, "JALR target: x9 = x10 + x12");
                end
                3: begin  // LUI / AUIPC (x8 and x31 preloaded so LUI can't pass by accident)
                    check_reg(5'd8,  32'd99,       "Setup: x8 = 99");
                    check_reg(5'd31, 32'd99,       "Setup: x31 = 99");
                    check_reg(5'd1,  32'h12345000, "LUI ignores its rs1 bits (x8 = 99)");
                    check_reg(5'd2,  32'h0000100c, "AUIPC: pc(12) + 0x1000");
                    check_reg(5'd3,  32'h12345678, "LUI + ADDI builds a 32-bit constant");
                    check_reg(5'd4,  32'hFFFFF000, "LUI with top bit set (rs1 bits = x31 = 99)");
                    check_reg(5'd5,  32'h00000018, "AUIPC with imm 0 = pc(24)");
                end
                4: begin
                    check_reg(5'd2,  32'hFFFFFFA1, "LB byte 0, sign-extended");
                    check_reg(5'd3,  32'h000000A1, "LBU byte 0, zero-extended");
                    check_reg(5'd4,  32'h00000043, "LB byte 1, positive");
                    check_reg(5'd5,  32'hFFFF8765, "LH upper half, sign-extended");
                    check_reg(5'd7,  32'h00008765, "LHU upper half");
                    check_reg(5'd8,  32'h876543A1, "LW still works");
                    check_mem(32'd4, 32'h0234FF00, "SB then SH: only their bytes written");
                    check_reg(5'd11, 32'h0234FF00, "LW reads back the merged word");
                end
            endcase
            check_reg(5'd6, 32'd7, "End marker reached");  
        end

        // Verification Summary
        $display("==================================================");
        if (error_count == 0) begin
            $display("SUCCESS: All %0d end-to-end integration tests passed!", test_count);
        end else begin
            $display("FAILURE: %0d out of %0d tests failed.", error_count, test_count);
        end
        $display("Retired %0d instructions in %0d cycles: IPC = %0.2f", retired, cycles, real'(retired) / cycles);
        $display("==================================================");

        $finish;
    end

endmodule
