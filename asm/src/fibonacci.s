.intel_syntax noprefix
.globl _FibonacciNaive
_FibonacciNaive:
    push rbp
    mov rbp, rsp
    push r15
    push r14
    push r13
    push r12
    push rbx
    mov dword ptr [rbp - 4], edi
    mov ecx, dword ptr [rbp - 4]
    mov eax, 1
    mov edx, 1
    cmp ecx, 2
    jg biggerthantwo
    cmp ecx, 0
    jle exitInvalidParam
    jmp retvalue
biggerthantwo:
    dec ecx
    add eax, edx
    mov ebx, eax
    sub ebx, edx
    mov edx, ebx
    cmp ecx, 2
    jg biggerthantwo
retvalue:
    pop rbx
    pop r12
    pop r13
    pop r14
    pop r15
    pop rbp
    ret
exitInvalidParam:
    mov eax, -1
    pop rbx
    pop r12
    pop r13
    pop r14
    pop r15
    pop rbp
    ret