	extern printf

	section .data

fmt:	db `Hello, Holberton\n`, 0

	section .text

	global main
main:
	push rbp

	mov rdi,fmt
	mov rax,0
	call printf

	pop rbp

	mov rax,0
	ret
