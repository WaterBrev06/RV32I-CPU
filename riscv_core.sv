`timescale 1ns / 1ps

module riscv_core(
    input  logic        clk,
    input  logic        rst,

    // Instruction memory (outside the core)
    output logic [31:0] imem_addr,
    input  logic [31:0] imem_rdata,

    // Data memory (outside the core)
    output logic [31:0] dmem_addr,
    output logic [31:0] dmem_wdata,
    output logic [3:0]  dmem_be,
    output logic        dmem_we,
    output logic        dmem_re,
    input  logic [31:0] dmem_rdata,

    output logic [31:0] wb_result // Exposes Write-Back result for testbench verification
    );
    
    // ========================================================================
    // SIGNAL DECLARATIONS BY PIPELINE STAGE
    // ========================================================================

    // ----- IF Stage -----
    logic [31:0] pc, next_pc, pc_plus_4;
    logic [31:0] if_instr;

    // ----- Hazard Control Signals -----
    logic        pc_stall;
    logic        if_id_stall;
    logic        if_id_flush;
    logic        id_ex_flush;
    logic        branch_taken;

    // ----- ID Stage -----
    logic [31:0] id_pc, id_instr;
    logic [4:0]  id_rs1_addr, id_rs2_addr, id_rd_addr;
    logic [31:0] id_rs1_data, id_rs2_data, id_imm;
    logic        id_reg_write, id_mem_to_reg, id_mem_read, id_mem_write;
    logic        id_branch, id_jump, id_jalr, id_alu_src, id_uses_rs1, id_uses_rs2, id_system;
    logic        id_valid;
    logic [1:0]  id_alu_op;
    logic [1:0]  id_alu_a_sel;

    // ----- EX Stage -----
    logic [31:0] ex_pc, ex_rs1_data, ex_rs2_data, ex_imm;
    logic [2:0]  ex_funct3;
    logic        ex_funct7_5, ex_op_bit5;
    logic [4:0]  ex_rs1_addr, ex_rs2_addr, ex_rd_addr;
    logic        ex_reg_write, ex_mem_to_reg, ex_mem_read, ex_mem_write, ex_branch, ex_alu_src, ex_system;
    logic [1:0]  ex_alu_op;
    logic [3:0]  ex_alu_ctrl;
    logic [1:0]  forward_a, forward_b;
    logic [31:0] alu_in1, alu_in2, forward_b_data;
    logic [31:0] ex_alu_out, ex_branch_target, ex_target, ex_result;
    logic        ex_zero;
    logic        ex_branch_take;
    logic        ex_valid;
    logic        ex_jump, ex_jalr;
    logic [1:0]  ex_alu_a_sel;

    // ----- MEM Stage -----
    logic        mem_reg_write, mem_mem_to_reg, mem_mem_read, mem_write_enable, mem_branch;
    logic [2:0]  mem_funct3;
    logic [31:0] mem_branch_target, mem_alu_out, mem_rs2_data, mem_read_data;
    logic        mem_zero;
    logic [4:0]  mem_rd_addr;
    logic        mem_valid;

    // ----- WB Stage -----
    logic        wb_reg_write, wb_mem_to_reg;
    logic [31:0] wb_read_data, wb_alu_out;
    logic [4:0]  wb_rd_addr;
    logic [31:0] wb_data;
    /* verilator lint_off UNUSEDSIGNAL */
    logic        wb_valid;     // read by the testbench IPC counters (retired-instruction count)
    /* verilator lint_on UNUSEDSIGNAL */

    // ----- CSR Unit -----
    logic [31:0] csr_rdata, csr_redirect_pc;
    logic        csr_redirect;

    assign wb_result = wb_data;


    // ========================================================================
    // 1. INSTRUCTION FETCH (IF) STAGE
    // ========================================================================

    // Program Counter Register
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            pc <= 32'd0;
        else if (!pc_stall)
            pc <= next_pc;
    end

    assign pc_plus_4 = pc + 32'd4;
    assign next_pc   = branch_taken ? ex_target : pc_plus_4;

    // Instruction Memory: outside the core
    assign imem_addr = pc;
    assign if_instr  = imem_rdata;

    // IF/ID Pipeline Register
    if_id_reg if_id (
        .clk       (clk),
        .rst       (rst),
        .stall     (if_id_stall),
        .flush     (if_id_flush),
        .valid_in  (1'b1),
        .pc_in     (pc),
        .instr_in  (if_instr),
        .pc_out    (id_pc),
        .instr_out (id_instr),
        .valid_out (id_valid)
    );


    // ========================================================================
    // 2. INSTRUCTION DECODE (ID) STAGE
    // ========================================================================

    assign id_rs1_addr = id_instr[19:15];
    assign id_rs2_addr = id_instr[24:20];
    assign id_rd_addr  = id_instr[11:7];

    // Main Control Unit
    control_unit control (
        .opcode     (id_instr[6:0]),
        .reg_write  (id_reg_write),
        .alu_src    (id_alu_src),
        .mem_to_reg (id_mem_to_reg),
        .mem_read   (id_mem_read),
        .mem_write  (id_mem_write),
        .branch     (id_branch),
        .jump       (id_jump),
        .jalr       (id_jalr),
        .system     (id_system),
        .uses_rs1   (id_uses_rs1),
        .uses_rs2   (id_uses_rs2),
        .alu_op     (id_alu_op),
        .alu_a_sel  (id_alu_a_sel)
    );

    // Register File
    regfile u_regfile (
        .clk       (clk),
        .reg_write (wb_reg_write),
        .rs1_addr  (id_rs1_addr),
        .rs2_addr  (id_rs2_addr),
        .rd_addr   (wb_rd_addr),
        .rd_data   (wb_data),
        .rs1_data  (id_rs1_data),
        .rs2_data  (id_rs2_data)
    );

    // Immediate Generator
    immgen ig (
        .instr   (id_instr),
        .imm_ext (id_imm)
    );

    // ID/EX Pipeline Register
    id_ex_reg id_ex (
        .clk            (clk),
        .rst            (rst),
        .flush          (id_ex_flush),
        .reg_write_in   (id_reg_write),
        .mem_to_reg_in  (id_mem_to_reg),
        .mem_read_in    (id_mem_read),
        .mem_write_in   (id_mem_write),
        .branch_in      (id_branch),
        .alu_src_in     (id_alu_src),
        .alu_op_in      (id_alu_op),
        .alu_a_sel_in   (id_alu_a_sel),
        .pc_in          (id_pc),
        .rs1_data_in    (id_rs1_data),
        .rs2_data_in    (id_rs2_data),
        .imm_in         (id_imm),
        .funct3_in      (id_instr[14:12]),
        .funct7_5_in    (id_instr[30]),
        .op_bit5_in     (id_instr[5]),
        .rs1_addr_in    (id_rs1_addr),
        .rs2_addr_in    (id_rs2_addr),
        .rd_addr_in     (id_rd_addr),
        .valid_in       (id_valid),
        .jump_in        (id_jump),
        .jalr_in        (id_jalr),
        .system_in      (id_system),

        .reg_write_out  (ex_reg_write),
        .mem_to_reg_out (ex_mem_to_reg),
        .mem_read_out   (ex_mem_read),
        .mem_write_out  (ex_mem_write),
        .branch_out     (ex_branch),
        .alu_src_out    (ex_alu_src),
        .alu_op_out     (ex_alu_op),
        .alu_a_sel_out  (ex_alu_a_sel),
        .pc_out         (ex_pc),
        .rs1_data_out   (ex_rs1_data),
        .rs2_data_out   (ex_rs2_data),
        .imm_out        (ex_imm),
        .funct3_out     (ex_funct3),
        .funct7_5_out   (ex_funct7_5),
        .op_bit5_out    (ex_op_bit5),
        .rs1_addr_out   (ex_rs1_addr),
        .rs2_addr_out   (ex_rs2_addr),
        .rd_addr_out    (ex_rd_addr),
        .valid_out      (ex_valid),
        .jump_out       (ex_jump),
        .jalr_out       (ex_jalr),
        .system_out     (ex_system)
    );


    // ========================================================================
    // 3. EXECUTE (EX) STAGE
    // ========================================================================

    // ALU Control Unit
    alu_control alu_ctrl_unit (
        .alu_op   (ex_alu_op),
        .funct3   (ex_funct3),
        .funct7_5 (ex_funct7_5),
        .op_bit5  (ex_op_bit5),
        .alu_ctrl (ex_alu_ctrl)
    );
    
    //CSR Unit
    csr_unit alu_csr_unit (
        .clk        (clk),
        .rst        (rst),
        .system     (ex_system),
        .funct3     (ex_funct3),
        .csr_addr   (ex_imm[11:0]),
        .rs1_field  (ex_rs1_addr),
        .rs1_val    (alu_in1),
        .pc         (ex_pc),
        .rdata      (csr_rdata),
        .redirect   (csr_redirect),
        .redirect_pc(csr_redirect_pc)
    );

    // Forwarding MUX for ALU Input A
    always_comb begin
        case (forward_a)
            2'b10:   alu_in1 = mem_alu_out;  // Forward from MEM stage
            2'b01:   alu_in1 = wb_data;      // Forward from WB stage
            default: alu_in1 = ex_rs1_data;  // Original register value
        endcase
    end

    // Forwarding MUX for Register Source 2 Data
    always_comb begin
        case (forward_b)
            2'b10:   forward_b_data = mem_alu_out;
            2'b01:   forward_b_data = wb_data;
            default: forward_b_data = ex_rs2_data;
        endcase
    end

    logic [31:0] alu_a;
    always_comb begin
        case (ex_alu_a_sel)
            2'b01: alu_a = ex_pc;   //AUIPC
            2'b10: alu_a = 32'd0;   //LUI
            default: alu_a = alu_in1; //fwd rs1
        endcase 
    end

    // MUX for ALU Input B (Register vs Immediate)
    assign alu_in2 = ex_alu_src ? ex_imm : forward_b_data;

    // Branch Target Adder
    assign ex_branch_target = ex_pc + ex_imm;

    // Execution ALU
    alu main_alu (
        .a        (alu_a),
        .b        (alu_in2),
        .alu_ctrl (ex_alu_ctrl),
        .alu_out  (ex_alu_out)
    );

    assign ex_target = csr_redirect ? csr_redirect_pc : (ex_jalr ? (ex_alu_out & ~32'd1) : ex_branch_target);
        
    //Branch Unit
    branch_unit u_bu (
        .a        (alu_in1),
        .b        (forward_b_data),
        .funct3   (ex_funct3),
        .take     (ex_branch_take)
    );

    assign ex_result = ex_jump ? (ex_pc + 32'd4) : (ex_system ? csr_rdata : ex_alu_out);

    // EX/MEM Pipeline Register
    ex_mem_reg ex_mem (
        .clk               (clk),
        .rst               (rst),
        .reg_write_in      (ex_reg_write),
        .mem_to_reg_in     (ex_mem_to_reg),
        .mem_read_in       (ex_mem_read),
        .mem_write_in      (ex_mem_write),
        .branch_in         (ex_branch),
        .branch_target_in  (ex_branch_target),
        .zero_in           (ex_zero),
        .alu_out_in        (ex_result),
        .rs2_data_in       (forward_b_data),
        .rd_addr_in        (ex_rd_addr),
        .valid_in          (ex_valid),
        .funct3_in         (ex_funct3),

        .reg_write_out     (mem_reg_write),
        .mem_to_reg_out    (mem_mem_to_reg),
        .mem_read_out      (mem_mem_read),
        .mem_write_out     (mem_write_enable),
        .branch_out        (mem_branch),
        .branch_target_out (mem_branch_target),
        .zero_out          (mem_zero),
        .alu_out_out       (mem_alu_out),
        .rs2_data_out      (mem_rs2_data),
        .rd_addr_out       (mem_rd_addr),
        .valid_out         (mem_valid),
        .funct3_out        (mem_funct3)
    );


    // ========================================================================
    // 4. MEMORY (MEM) STAGE
    // ========================================================================

    assign branch_taken = ex_jump || (ex_branch && ex_branch_take) || csr_redirect;

    // Load/Store Unit: byte enables for stores, select + extend for loads.
    // The data memory itself is outside the core.
    lsu u_lsu (
        .mem_read   (mem_mem_read),
        .mem_write  (mem_write_enable),
        .funct3     (mem_funct3),
        .addr       (mem_alu_out),
        .store_data (mem_rs2_data),
        .dmem_rdata (dmem_rdata),
        .dmem_addr  (dmem_addr),
        .dmem_wdata (dmem_wdata),
        .dmem_be    (dmem_be),
        .dmem_we    (dmem_we),
        .dmem_re    (dmem_re),
        .load_data  (mem_read_data)
    );

    // MEM/WB Pipeline Register
    mem_wb_reg mem_wb (
        .clk            (clk),
        .rst            (rst),
        .reg_write_in   (mem_reg_write),
        .mem_to_reg_in  (mem_mem_to_reg),
        .read_data_in   (mem_read_data),
        .alu_out_in     (mem_alu_out),
        .rd_addr_in     (mem_rd_addr),
        .valid_in       (mem_valid),

        .reg_write_out  (wb_reg_write),
        .mem_to_reg_out (wb_mem_to_reg),
        .read_data_out  (wb_read_data),
        .alu_out_out    (wb_alu_out),
        .rd_addr_out    (wb_rd_addr),
        .valid_out      (wb_valid)
    );


    // ========================================================================
    // 5. WRITE-BACK (WB) STAGE
    // ========================================================================

    assign wb_data = wb_mem_to_reg ? wb_read_data : wb_alu_out;


    // ========================================================================
    // HAZARD DETECTION & FORWARDING UNITS
    // ========================================================================

    forwarding_unit fwd (
        .id_ex_rs1        (ex_rs1_addr),
        .id_ex_rs2        (ex_rs2_addr),
        .ex_mem_rd        (mem_rd_addr),
        .mem_wb_rd        (wb_rd_addr),
        .ex_mem_reg_write (mem_reg_write),
        .mem_wb_reg_write (wb_reg_write),
        .forward_a        (forward_a),
        .forward_b        (forward_b)
    );

    hazard_unit hazard (
        .if_id_rs1      (id_rs1_addr),
        .if_id_rs2      (id_rs2_addr),
        .id_ex_rd       (ex_rd_addr),
        .id_ex_mem_read (ex_mem_read),
        .branch_taken   (branch_taken),
        .pc_stall       (pc_stall),
        .if_id_stall    (if_id_stall),
        .if_id_flush    (if_id_flush),
        .id_ex_flush    (id_ex_flush),
        .uses_rs1       (id_uses_rs1),
        .uses_rs2       (id_uses_rs2)
    );
    
endmodule
