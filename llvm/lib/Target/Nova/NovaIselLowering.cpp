//@s nova-isel-lowering-cpp-1

//===- NovaIselLowering.cpp - Nova DAG Lowering Implementation -----------===//
#include "NovaIselLowering.h"
#include "NovaMCTargetDesc.h"

using namespace llvm;

#define DEBUG_TYPE "nova-isel"

NovaTargetLowering::NovaTargetLowering(const TargetMachine &TM,
                                       const NovaSubtarget &STI)
    : TargetLowering(TM) {}

//- nova-isel-lowering-cpp-1

//@s nova-isel-lowering-cpp-2

SDValue NovaTargetLowering::LowerReturn(SDValue Chain, CallingConv::ID CallConv,
                               bool isVarArg,
                               const SmallVectorImpl<ISD::OutputArg> &Outs,
                               const SmallVectorImpl<SDValue> &OutVals,
                               const SDLoc &dl, SelectionDAG &DAG) const {
  // handle only integer return values
  // we need to copy the value to the v0 register.
  if (Outs.size() > 1) {
    report_fatal_error("Multiple return values not supported\n"
    "This could be because the return type is a struct or a large integer"
    "that got split into multiple registers", false);
  }
  for (const SDValue &OutVal : OutVals) {
    if (!OutVal.getValueType().isScalarInteger() && OutVal.getValueType().getScalarSizeInBits() > 32) {
      report_fatal_error("Only i32 return values are supported", false);
    }
    Chain = DAG.getCopyToReg(Chain, dl, Nova::V0, OutVal);
  }
  return Chain;
}
//- nova-isel-lowering-cpp-2

SDValue NovaTargetLowering::LowerCall(TargetLowering::CallLoweringInfo &CLI,
  SmallVectorImpl<SDValue> &InVals) const {
    return SDValue();
  }

bool NovaTargetLowering::CanLowerReturn(CallingConv::ID CallConv, MachineFunction &MF,
    bool IsVarArg,
    const SmallVectorImpl<ISD::OutputArg> &Outs,
    LLVMContext &Context, const Type *RetTy) const{
      return true;
}