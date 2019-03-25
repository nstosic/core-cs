.intel_syntax noprefix
.globl _BinarySearch
_BinarySearch:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    push r15
    push r14
    push r13
    push r12
    push rbx
    mov dword ptr [rbp - 4], edi
    mov qword ptr [rbp - 12], rsi
    mov dword ptr [rbp - 16], edx
    mov ecx, dword ptr [rbp - 16]
    cmp ecx, 0
    je notfound
    mov rax, qword ptr [rbp - 12]
    mov eax, dword ptr [rax]
    cmp eax, dword ptr [rbp - 4]
    jg notfound
    je retzeroindex
    xor rbx, rbx
    mov ebx, ecx
    dec ebx
    imul ebx, 4
    add rbx, qword ptr [rbp - 12]
    mov eax, dword ptr [rbx]
    cmp eax, dword ptr [rbp - 4]
    jl notfound
    je retlastindex
    mov rbx, 1
    xor rax, rax
binarysearchloop:
    cmp ecx, 0
    je oddevenfinish
    sar ecx, 1
    imul ebx, ecx
    add eax, ebx
    mov ebx, eax
    imul ebx, 4
    add rbx, qword ptr [rbp - 12]
    mov ebx, dword ptr [rbx]
    cmp ebx, dword ptr [rbp - 4]
    je retvalue
    jg decpivot
    mov ebx, 1
    jmp binarysearchloop
decpivot:
    mov ebx, -1
    jmp binarysearchloop
retzeroindex:
    mov eax, 0
    jmp retvalue
retlastindex:
    mov eax, dword ptr [rbp - 16]
    dec eax
    jmp retvalue
oddevenfinish:
    mov ecx, dword ptr [rbp - 16]
    and ecx, 1
    cmp ecx, 0
    je notfound
    add eax, ebx
    mov ebx, eax
    imul ebx, 4
    add rbx, qword ptr [rbp - 12]
    mov ebx, dword ptr [rbx]
    cmp ebx, dword ptr [rbp - 4]
    je retvalue
notfound:
    mov eax, -1
retvalue:
    pop rbx
    pop r12
    pop r13
    pop r14
    pop r15
    add rsp, 16
    pop rbp
    ret