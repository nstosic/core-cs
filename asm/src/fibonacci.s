.intel_syntax noprefix
.globl _FibonacciNaive
_FibonacciNaive:
    push rbp
    mov rbp, rsp
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
    pop rbp
    ret
exitInvalidParam:
    mov eax, -1
    pop rbp
    ret