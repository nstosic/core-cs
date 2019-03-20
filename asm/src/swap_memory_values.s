.intel_syntax noprefix
.globl	_SwapTwoValuesInMemory
_SwapTwoValuesInMemory:
	push rbp
	mov	rbp, rsp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	rsi, qword ptr [rbp - 8]
	mov	eax, dword ptr [rsi]
	mov	rdi, qword ptr [rbp - 16]
	mov	edx, dword ptr [rdi]
	mov	dword ptr [rsi], edx
	mov	dword ptr [rdi], eax
	pop	rbp
	ret