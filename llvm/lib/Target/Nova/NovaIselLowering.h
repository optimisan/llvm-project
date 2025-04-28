//@s nova-isel-lowering-1
//===-- Nova DAG Lowering Interface -----------------------------------  --===//
// This file defines the interfaces that Nova uses to lower LLVM IR to
// SelectionDAG operations.
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_NOVA_NOVAISELLOWERING_H
#define LLVM_LIB_TARGET_NOVA_NOVAISELLOWERING_H

#include "llvm/CodeGen/ISDOpcodes.h"
#include "llvm/CodeGen/TargetLowering.h"
namespace llvm {

namespace NovaISD {
enum NodeType : unsigned {
  FIRST_NUMBER = ISD::BUILTIN_OP_END,

  // Return
  Ret,
};
} // end namespace NovaISD

class NovaSubtarget;

class NovaTargetLowering : public TargetLowering {
public:
  explicit NovaTargetLowering(const TargetMachine &TM,
                              const NovaSubtarget &STI);

  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool isVarArg,
              const SmallVectorImpl<ISD::OutputArg> &Outs,
              const SmallVectorImpl<SDValue> &OutVals, const SDLoc &dl,
              SelectionDAG &DAG) const override;

  SDValue LowerCall(TargetLowering::CallLoweringInfo &CLI,
                    SmallVectorImpl<SDValue> &InVals) const override;

  bool CanLowerReturn(CallingConv::ID CallConv, MachineFunction &MF,
                      bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      LLVMContext &Context, const Type *RetTy) const override;
  SDValue LowerFormalArguments(
      SDValue Chain, CallingConv::ID /*CallConv*/, bool /*isVarArg*/,
      const SmallVectorImpl<ISD::InputArg> & /*Ins*/, const SDLoc & /*dl*/,
      SelectionDAG & /*DAG*/, SmallVectorImpl<SDValue> & /*InVals*/) const override {
        return Chain;
  }
  /// getTargetNodeName - This method returns the name of a target specific
  //  DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;
};

} // namespace llvm
#endif

//- nova-isel-lowering-1
