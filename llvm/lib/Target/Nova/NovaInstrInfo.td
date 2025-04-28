//@s nova-instr-info-1
include "NovaInstrFormats.td"
// This file describes the Nova instruction set.

//==----------- All SD nodes and patterns --------//
// Procedure return
def NovaRetSDN : SDNode<"NovaISD::Ret", SDTNone, [SDNPHasChain]>;


//==----------- All instructions -----------------//
def PseudoRet : NovaInst<(outs), (ins), "ret"> {
  let isReturn = 1;
  let isTerminator = 1;
}

def ADD_rr : NovaInst<(outs GPR32:$dst), (ins GPR32:$src1, GPR32:$src2),
                      "ADD_rii $dst, $src1, $src2">;
def ADD_ri : NovaInst<(outs GPR32:$dst), (ins GPR32:$src1, i32imm:$imm),
                      "ADD_ri $dst, $src1, $imm"> {
  // let Pattern = [(set (i32 GPR32:$dst), i32:$imm)];
}

//==------------ All patterns to match SD to instructions ---------//
def : Pat<(NovaRetSDN), (PseudoRet)>;
def : Pat<(add i32:$src1, i32:$src2), (ADD_rr i32:$src1, i32:$src2)>;
// Materialize constants with add zero, immediate
def : Pat<(i32 imm:$imm), (ADD_ri ZERO, imm:$imm)>;
// def : Pat<(i32 (add i32:$dst, i32)), (i32 (ADD_rr GPR32:$dst, ZERO))>;
// def : Pat<(set i32:$dst, (i32 i32:$imm)), (ADD_ri i32:$dst, i32imm:$imm)>;

def MOV_ri : Instruction {
  let OutOperandList = (outs GPR32:$dst);
  let InOperandList = (ins i32imm:$imm);
  let AsmString = "MOV_ri $dst, $imm";
  // let Pattern = [(set (i32 GPR32:$dst), (i32 i32:$imm))];
  let isMoveImm = 1;
  let Namespace = "Nova";
}

// def: Pat<(set(i32 GPR32:$dst), (i32 i32imm:$imm)), (MOV_ri GPR32:$dst, $imm)>;

def callseq_end : SDNode<"ISD::CALLSEQ_END", SDTNone, [SDNPHasChain, SDNPOptInGlue]>;

def ADJCALLSTACKDOWN : Instruction {
  let OutOperandList = (outs);
  let Namespace = "Nova";
  let InOperandList = (ins);
  let AsmString = "ADJCALLSTACKDOWN";
  let Pattern = [(callseq_end)];
}

def ADJCALLSTACKUP : Instruction {
  let OutOperandList = (outs);
  let Namespace = "Nova";
  let InOperandList = (ins);
  let AsmString = "ADJCALLSTACKUP";
  let Pattern = [(callseq_end)];
}

//- nova-instr-info-1

