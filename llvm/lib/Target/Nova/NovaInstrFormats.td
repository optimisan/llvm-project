class NovaInst<dag outs, dag ins, string asmString> : Instruction {
  let Namespace = "Nova";
  let OutOperandList = outs;
  let InOperandList = ins;
  let AsmString = asmString;
}

class PseudoNovaInst<dag outs, dag ins, string asmString> : NovaInst<outs, ins, asmString> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}
