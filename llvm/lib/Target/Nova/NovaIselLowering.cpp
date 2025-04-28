//@s nova-isel-lowering-cpp-1

//===- NovaIselLowering.cpp - Nova DAG Lowering Implementation -----------===//
#include "NovaIselLowering.h"
#include "NovaMCTargetDesc.h"
#include "NovaSubtarget.h"

using namespace llvm;

#define DEBUG_TYPE "nova-isel"

NovaTargetLowering::NovaTargetLowering(const TargetMachine &TM,
                                       const NovaSubtarget &STI)
    : TargetLowering(TM) {
      addRegisterClass(MVT::i32, &Nova::GPR32RegClass);
      // Disallow floating types

      computeRegisterProperties(STI.getRegisterInfo());
    }

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
    "This could be because the return type is a struct or a large integer "
    "that got split into multiple registers", false);
  }
  SDValue Glue;
  for (unsigned i = 0, e = Outs.size(); i != e; ++i) {
    const ISD::OutputArg &Out = Outs[i];
    const SDValue &OutVal = OutVals[i];
    if (!Out.ArgVT.isScalarInteger() || Out.ArgVT.getScalarSizeInBits() > 32) {
      report_fatal_error("Only i32 return values are supported", false);
    }
    Chain = DAG.getCopyToReg(Chain, dl, Nova::V0, OutVal, Glue);
    Glue = Chain.getValue(1);
  }
  auto Reg = DAG.getRegister(Nova::V0, MVT::i32);

  return DAG.getNode(NovaISD::Ret, dl,MVT::Other, Chain, Reg, Glue);
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

const char *NovaTargetLowering::getTargetNodeName(unsigned Opcode) const {
  switch (Opcode) {
  case NovaISD::Ret:
    return "NovaISD::Ret";
  default:
    return "Unknown NovaISD::Node";
  }
}