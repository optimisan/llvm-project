//@s create-nova-td end
// This is the top tablegen file that pulls in other code
// specific to the Nova target.

include "llvm/Target/Target.td"

include "NovaRegisterInfo.td"
include "NovaInstrInfo.td"

def : ProcessorModel<"generic", NoSchedModel, []>;

def NovaInstrInfo : InstrInfo {}

def Nova : Target {
  let InstructionSet = NovaInstrInfo;
}
//- create-nova-td