module csr_unit (
    input  logic        clk,
    input  logic        rst,
    input  logic        system,        // SYSTEM opcode in EX (0 for bubbles)
    input  logic [2:0]  funct3,
    input  logic [11:0] csr_addr,      // instr[31:20]: the CSR, or which of ecall/ebreak/mret
    input  logic [4:0]  rs1_field,     // rs1 number, or zimm for the *i forms
    input  logic [31:0] rs1_val,       // forwarded rs1
    input  logic [31:0] pc,            // PC of the instruction in EX
    output logic [31:0] rdata,         // old CSR value, written to rd
    output logic        redirect,      // trap or mret: change the PC
    output logic [31:0] redirect_pc
);
    logic [31:0] mstatus, mtvec, mscratch, mepc, mcause, mtval;

    // ---- Decode ----
    logic is_csr, is_ecall, is_ebreak, is_mret;
    assign is_csr    = system && (funct3 != 3'b000);
    assign is_ecall  = system && (funct3 == 3'b000) && (csr_addr == 12'h000);
    assign is_ebreak = system && (funct3 == 3'b000) && (csr_addr == 12'h001);
    assign is_mret   = system && (funct3 == 3'b000) && (csr_addr == 12'h302);

    // ---- Read: unimplemented CSRs read as 0 ----
    always_comb begin
        case (csr_addr)
            12'h300: rdata = mstatus;
            12'h301: rdata = 32'h4000_0100;    // misa: RV32 (bits 31:30 = 01), I extension (bit 8)
            12'h305: rdata = mtvec;
            12'h340: rdata = mscratch;
            12'h341: rdata = mepc;
            12'h342: rdata = mcause;
            12'h343: rdata = mtval;
            default: rdata = 32'd0;            // includes mhartid (0xF14) = hart 0
        endcase
    end

    // ---- Write value ----
    logic [31:0] src, wdata;
    logic        wen;
    assign src = funct3[2] ? {27'd0, rs1_field} : rs1_val;   // *i forms: 5-bit zimm
    always_comb begin
        case (funct3[1:0])
            2'b01:   wdata = src;             // CSRRW: replace               (Q1)
            2'b10:   wdata = rdata | src;             // CSRRS: set the bits in src   (Q2)
            default: wdata = rdata & ~src;             // CSRRC: clear the bits in src (Q3)
        endcase
    end
    // CSRRS/CSRRC with rs1 = x0 (or zimm = 0) only read
    assign wen = is_csr && (funct3[1:0] == 2'b01 || rs1_field != 5'd0);

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            mstatus <= '0; mtvec <= '0; mscratch <= '0; mepc <= '0; mcause <= '0; mtval <= '0;
        end else if (is_ecall || is_ebreak) begin
            mepc   <= pc;
            mcause <= is_ecall ? 32'd11 : 32'd3;   // 11: ECALL from M-mode, 3: breakpoint
            mtval  <= '0;
        end else if (wen) begin
            case (csr_addr)
                12'h300: mstatus  <= wdata;
                12'h305: mtvec    <= {wdata[31:2], 2'b00};   // direct mode only
                12'h340: mscratch <= wdata;
                12'h341: mepc     <= {wdata[31:2], 2'b00};   // instructions are 4-byte aligned
                12'h342: mcause   <= wdata;
                12'h343: mtval    <= wdata;
                default: ;                                   // unimplemented: write ignored
            endcase
        end
    end

    assign redirect    = is_ecall || is_ebreak || is_mret;
    assign redirect_pc = is_mret ? mepc : mtvec;
endmodule
