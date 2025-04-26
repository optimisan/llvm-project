//@s reginfo-cpp1
#include "NovaRegisterInfo.h"
#include "NovaFrameLowering.h"
#include "NovaMCTargetDesc.h"

#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/MC/MCRegister.h"

using namespace llvm;

#define DEBUG_TYPE "nova-reg-info"

#define GET_REGINFO_TARGET_DESC
#include "NovaGenRegisterInfo.inc"

using namespace llvm;

NovaRegisterInfo::NovaRegisterInfo() : NovaGenRegisterInfo(Nova::RA) {}

const MCPhysReg *
NovaRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  static const MCPhysReg CSRList[] = {
      Nova::SP, // Stack Pointer
      Nova::FP, // Frame Pointer
      Nova::S0, // R0
  };
  return CSRList;
}

BitVector NovaRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  return BitVector();
}

bool NovaRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                           int SPAdj, unsigned FIOperandNum,
                                           RegScavenger *RS) const {
                                            return true;
                                           }

Register NovaRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return Nova::FP;
}

//- reginfo-cpp1
