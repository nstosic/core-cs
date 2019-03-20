.intel_syntax noprefix
.globl _FibonacciNaive
_FibonacciNaive:
    push rbp
    mov rbp, rsp
    mov dword ptr [rbp - 8], edi
    mov ecx, dword ptr [rbp - 8]
    mov edx, ecx
    and edx, 0x80000000
    cmp edx, 0
    jnz exitInvalidParam
    mov eax, 1
    cmp ecx, 0
    jz retifzero
    sub ecx, 1
    push rdi
    mov edi, ecx
    call _FibonacciNaive
    pop rdi
    mov edx, dword ptr [rbp - 8]
    imul eax, edx
retifzero:
    pop rbp
    ret
exitInvalidParam:
    mov eax, -1
    pop rbp
    ret