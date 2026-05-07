set(ANALYSIS "AP_GEN_DELPHES_DM_R3")

target_sources(RunAnalysis PRIVATE ${ANALYSIS}/src/HEPHeroB.cpp ${ANALYSIS}/src/HEPRoutines.cpp ${ANALYSIS}/src/HEPWeights.cpp ${ANALYSIS}/src/HEPVerticalSystematics.cpp ${ANALYSIS}/src/EXPTools.cpp ${ANALYSIS}/src/ANATools.cpp)
