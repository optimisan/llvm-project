//@s nova-tm-cpp removed
// #include "llvm/MC/TargetRegistry.h"
// #include "llvm/Support/Compiler.h"
// #include "llvm/TargetParser/Triple.h"

// using namespace llvm;

// static Target &getTheNovaTarget() {
//     static Target TheNovaTarget;
//     return TheNovaTarget;
// }

// extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeNovaTargetInfo() {
//     llvm::RegisterTarget<llvm::Triple::mipsnova> X(::getTheNovaTarget(), "mipsnova", "MipsNova (32-bit big endian)", "Nova");
// }

// extern "C" void LLVMInitializeNovaTargetMC() {
//     // TODO: Add initialize target MC
// }

// extern "C" void LLVMInitializeNovaTarget() {
//     // TODO: Add initialize target
// }
//- nova-tm-cpp

//@s deleted-mc-init delete
// extern "C" void LLVMInitializeNovaTargetMC() {
//     // TODO: Add initialize target MC
// }
//- deleted-mc-init


//@s old-get-the-nova removed
// static Target &getTheNovaTarget() {
//- old-get-the-nova

//@s nova-target-info-tm
#include "Nova.h"
#include "NovaISelDAGToDAG.h"
#include "NovaTargetInfo.h"
//- nova-target-info-tm
#include "NovaTargetMachine.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/PassRegistry.h"
#include "llvm/Support/Compiler.h"
#include "llvm/TargetParser/Triple.h"

using namespace llvm;

//@s new-get-the-nova replace=old-get-the-nova
Target &llvm::getTheNovaTarget() {
//- new-get-the-nova
    static Target TheNovaTarget;
    return TheNovaTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeNovaTargetInfo() {
    llvm::RegisterTarget<llvm::Triple::mipsnova> X(::getTheNovaTarget(), "mipsnova", "MipsNova (32-bit big endian)", "Nova");
};

extern "C" void LLVMInitializeNovaTarget() {
    RegisterTargetMachine<NovaTargetMachine> X(getTheNovaTarget());

    auto &Registry = *PassRegistry::getPassRegistry();
    initializeNovaDAGToDAGISelLegacyPass(Registry);
}


namespace {
class NovaPassConfig : public TargetPassConfig {
public:
    NovaPassConfig(NovaTargetMachine &TM, PassManagerBase &PM)
        : TargetPassConfig(TM, PM) {}

    NovaTargetMachine &getNovaTargetMachine() const {
        return getTM<NovaTargetMachine>();
    }
    bool addInstSelector() override {
        addPass(createNovaISelDagLegacy(getNovaTargetMachine(), getOptLevel()));
        return false;
    }
    void addPreEmitPass() override {}
};
} // namespace

TargetPassConfig *NovaTargetMachine::createPassConfig(PassManagerBase &PM) {
    return new NovaPassConfig(*this, PM);
}

