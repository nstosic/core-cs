# Assembler

This directory serves to provide solutions for problems (almost exclusively scoped to a single function) written in x86-64 instruction set.

## Instruction set
All the assembly functions are written using Intel 64 architecture instruction set.

## Syntax
All the assembly functions are written in `.intel_syntax noprefix`.

## Calling convention
Unless otherwise specified, all assembly functions follow the System V AMD64 ABI calling convention specification. To further specify - RBX, R12, R13, R14 and R15 registers are considered volatile and are callee-saved. Furthermore, RBP is used to store the value of caller's stack frame and to make it current stack frame just before returning from callee function.

This is the prologue and epliogue of the functions that satisfies the above constraints:
```
; Prologue
push rbp
mov rbp, rsp
sub rsp, ? ; Allocate space for local variables
push r15
push r14
push r13
push r12
push rbx

;...

; Epilogue
pop rbx
pop r12
pop r13
pop r14
pop r15
add rsp, ? ; Deallocate space that was allocated for local variables
pop rbp
ret
```

## Name mangling
Unit tests are written in C++ so they use `extern 'C'` wrapper when declaring function headers for assembly written functions that they are testing. However, since different compilers have their own rules on prefixing C function names with underscore, all assembly function names start with `_` and unit test declarations use `ASSEMBLY_DECLARATION(x, y)` and `ASSEMBLY_CALL(x)` macros which expand to different values based on `BUILD_ON_TRAVIS` build flag to compensate for this discrepancy.
