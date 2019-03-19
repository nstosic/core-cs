enable_language(C ASM)

set(GOOGLETEST_ROOT asm/src CACHE STRING "asm source root")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "asm/src/*.s")
set_source_files_properties(${SOURCES} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")
add_library(asm_source ${SOURCES})