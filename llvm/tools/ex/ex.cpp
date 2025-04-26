#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/TargetParser/Triple.h"
#include <optional>

using namespace llvm;

int main(int argc, char *argv[]) {
    InitLLVM X(argc, argv);

    InitializeAllTargets();
    InitializeAllTargetMCs();

    // Triple T("x86_64-unknown-linux-gnu");
    Triple T("mips--");
    llvm::outs() << "Triple: " << T.str() << "\n";
    std::string error = "no target found\n";

    const Target* TheMipsTarget = TargetRegistry::lookupTarget(T, error);

    std::optional<Reloc::Model> RM = std::nullopt;
    TargetMachine* TM = TheMipsTarget->createTargetMachine("mips--", "", "", TargetOptions(), RM);

    MCInstrInfo* MII = TheMipsTarget->createMCInstrInfo();
    const MCInstrDesc &IDesc = MII->get(841);
    llvm::outs() << IDesc.isAsCheapAsAMove();
    

    return 0;
}
