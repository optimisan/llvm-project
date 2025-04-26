//@s create-reginfo

#include "NovaMCTargetDesc.h"
#include "MCTargetDesc/NovaMCAsmInfo.h"
#include "NovaTargetInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#define ENABLE_INSTR_PREDICATE_VERIFIER
#include "NovaGenInstrInfo.inc"

#define GET_REGINFO_MC_DESC
#include "NovaGenRegisterInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "NovaGenSubtargetInfo.inc"


static MCRegisterInfo* createNovaMCRegisterInfo(const Triple &TT) {
    MCRegisterInfo *X = new MCRegisterInfo();
    InitNovaMCRegisterInfo(X, Nova::RA);
    return X;
}

static MCInstrInfo* createNovaMCInstrInfo() {
    MCInstrInfo *X = new MCInstrInfo();
    InitNovaMCInstrInfo(X);
    return X;
}

static MCSubtargetInfo* createNovaSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
    if (CPU.empty())
        CPU = "generic";
    return createNovaMCSubtargetInfoImpl(TT, CPU, CPU, FS);
}

static MCAsmInfo* createNovaMCAsmInfo(const MCRegisterInfo &MRI, const Triple &TT, const MCTargetOptions &Options) {
    MCAsmInfo *X = new NovaMCAsmInfo(TT);
    unsigned SP = MRI.getDwarfRegNum(Nova::SP, true);
    MCCFIInstruction Inst = MCCFIInstruction::createDefCfaRegister(nullptr, SP);
    X->addInitialFrameState(Inst);
    return X;
}

extern "C" void LLVMInitializeNovaTargetMC() {
    Target *T = &getTheNovaTarget();
    TargetRegistry::RegisterMCRegInfo(*T, createNovaMCRegisterInfo);

    TargetRegistry::RegisterMCInstrInfo(*T, createNovaMCInstrInfo);
    TargetRegistry::RegisterMCSubtargetInfo(*T, createNovaSubtargetInfo);
    TargetRegistry::RegisterMCAsmInfo(*T, createNovaMCAsmInfo);
}

//- create-reginfo