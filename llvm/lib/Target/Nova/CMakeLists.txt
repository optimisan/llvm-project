#@s nova-cmake1 removed
# add_llvm_component_group(Nova)

# add_llvm_target(NovaCodeGen
#   MipsNovaTargetMachine.cpp

#   LINK_COMPONENTS
#   MC
#   TargetParser
#   Target

#   ADD_TO_COMPONENT
#   Nova
#   )

#- nova-cmake1


add_llvm_component_group(Nova)

#@s cmake-reg-info end
set(LLVM_TARGET_DEFINITIONS Nova.td)

tablegen(LLVM NovaGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM NovaGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM NovaGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM NovaGenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(NovaCommonTableGen)
#- cmake-reg-info

add_llvm_target(NovaCodeGen
  NovaTargetMachine.cpp
#@s cmake-reg-info-cpp end
  NovaRegisterInfo.cpp
#- cmake-reg-info-cpp
#@s cmake-mc-tdesc end
  NovaMCTargetDesc.cpp
#- cmake-mc-tdesc
#@s cmake-subtarget end
  NovaSubtarget.cpp
#- cmake-subtarget
#@s cmake-isel-lowering end
  NovaIselLowering.cpp
#- cmake-isel-lowering
  NovaInstrInfo.cpp
  NovaISelDAGToDAG.cpp
  MCTargetDesc/NovaMCAsmInfo.cpp
  NovaTargetObjectFile.cpp

  LINK_COMPONENTS
  MC
  TargetParser
  Target

  ADD_TO_COMPONENT
  Nova
)
