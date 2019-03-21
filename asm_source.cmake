enable_language(C ASM)

set(ASM_SOURCE_ROOT asm/src CACHE STRING "asm source root")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "asm/src/*.s")
set_source_files_properties(${SOURCES} PROPERTIES COMPILE_FLAGS "-xassembler-with-cpp")
add_library(asm_source ${SOURCES})