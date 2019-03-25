.intel_syntax noprefix
.globl	_SwapTwoValuesInMemory
_SwapTwoValuesInMemory:
	push rbp
	mov	rbp, rsp
	sub rsp, 16
	push r15
	push r14
	push r13
	push r12
	push rbx
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	rsi, qword ptr [rbp - 8]
	mov	eax, dword ptr [rsi]
	mov	rdi, qword ptr [rbp - 16]
	mov	edx, dword ptr [rdi]
	mov	dword ptr [rsi], edx
	mov	dword ptr [rdi], eax
	pop rbx
	pop r12
	pop r13
	pop r14
	pop r15
	add rsp, 16
	pop	rbp
	ret