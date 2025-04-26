//@s nova-instr-info-1
// This file describes the Nova instruction set.

// Procedure return
def NovaRetSDN : SDNode<"NovaISD::Ret", SDTNone, [SDNPHasChain]>;

let Namespace = "Nova" in {
def PseudoRet : Instruction {
  let OutOperandList = (outs);
  let InOperandList = (ins);
  let AsmString = "ret";
  let Pattern = [(NovaRetSDN)];
  let isReturn = 1;
  let isTerminator = 1;
  // let isPseudo = 1;
}
}

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

