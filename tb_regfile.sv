`timescale 1ns / 1ps

module tb_regfile;

    // Testbench signals
    logic        clk;
    logic        reg_write;
    logic [4:0]  rs1_addr;
    logic [4:0]  rs2_addr;
    logic [4:0]  rd_addr;
    logic [31:0] rd_data;

    logic [31:0] rs1_data;
    logic [31:0] rs2_data;

    int error_count = 0;
    int test_count  = 0;

    // Instantiate Unit Under Test (UUT)
    regfile uut (
        .clk       (clk),
        .reg_write (reg_write),
        .rs1_addr  (rs1_addr),
        .rs2_addr  (rs2_addr),
        .rd_addr   (rd_addr),
        .rd_data   (rd_data),
        .rs1_data  (rs1_data),
        .rs2_data  (rs2_data)
    );

    // Clock generation: 100 MHz clock (10ns period)
    always #5 clk = ~clk;

    // Task to write data into a register on the rising clock edge
    task automatic write_reg(
        input logic [4:0]  addr,
        input logic [31:0] data,
        input logic        we
    );
        @(negedge clk); // Drive inputs on negative clock edge to meet setup time
        rd_addr   = addr;
        rd_data   = data;
        reg_write = we;
        @(posedge clk); // Trigger write on positive edge
        #1;             // Small hold time
        reg_write = 1'b0;
    endtask

    // Task to asynchronously read and verify both ports
    task automatic check_read(
        input logic [4:0]  a1,
        input logic [31:0] exp1,
        input logic [4:0]  a2,
        input logic [31:0] exp2,
        input string       test_name
    );
        rs1_addr = a1;
        rs2_addr = a2;
        #2; // Allow combinational propagation

        test_count++;

        if (rs1_data !== exp1 || rs2_data !== exp2) begin
            $display("FAIL [%s]:", test_name);
            $display("  Port 1 (x%0d): Expected = 0x%h, Got = 0x%h", a1, exp1, rs1_data);
            $display("  Port 2 (x%0d): Expected = 0x%h, Got = 0x%h", a2, exp2, rs2_data);
            error_count++;
        end else begin
            $display("PASS [%s]: Port 1 (x%0d) = 0x%h, Port 2 (x%0d) = 0x%h", test_name, a1, rs1_data, a2, rs2_data);
        end
    endtask

    initial begin
        // Initialize signals
        clk       = 0;
        reg_write = 0;
        rs1_addr  = 0;
        rs2_addr  = 0;
        rd_addr   = 0;
        rd_data   = 0;

        $display("============================================");
        $display(" STARTING REGISTER FILE SELF-CHECK TESTBENCH");
        $display("============================================");

        // 1. Initial State Check (x0 must equal 0)
        check_read(5'd0, 32'h0000_0000, 5'd0, 32'h0000_0000, "Initial Read x0");

        // 2. Write to x1 and Dual Read back
        write_reg(5'd1, 32'hDEAD_BEEF, 1'b1);
        check_read(5'd1, 32'hDEAD_BEEF, 5'd0, 32'h0000_0000, "Write to x1 & Read x1/x0");

        // 3. Immutability Check: Attempt Write to x0
        write_reg(5'd0, 32'hCAFE_BABE, 1'b1);
        check_read(5'd0, 32'h0000_0000, 5'd1, 32'hDEAD_BEEF, "x0 Immutability Check");

        // 4. Write Enable Disabled Check (reg_write = 0)
        write_reg(5'd2, 32'h1234_5678, 1'b0);
        check_read(5'd2, 32'hxxxx_xxxx, 5'd1, 32'hDEAD_BEEF, "Write Disabled Guard Check");

        // 5. Simultaneous Read on Both Ports (x1 and x2)
        write_reg(5'd2, 32'h8765_4321, 1'b1);
        check_read(5'd1, 32'hDEAD_BEEF, 5'd2, 32'h8765_4321, "Dual Simultaneous Read (x1 & x2)");

        // 6. Max Address Test (x31)
        write_reg(5'd31, 32'hFFFF_FFFF, 1'b1);
        check_read(5'd31, 32'hFFFF_FFFF, 5'd0, 32'h0000_0000, "Write/Read Highest Register x31");

        // Verification Summary
        $display("============================================");
        if (error_count == 0) begin
            $display("SUCCESS: All %0d test cases passed!", test_count);
        end else begin
            $display("FAILURE: %0d out of %0d test cases failed.", error_count, test_count);
        end
        $display("============================================");

        $finish;
    end

endmodule