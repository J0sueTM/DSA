section .data
	msg db "Hello github", 0xa
	msglen equ $ - msg

section .text
	global _start

_start:
	call _print_test_hello

	mov rax, 60 ; sys_exit
	mov rdx, 0  ; no error
	syscall

_print_test_hello:
	mov rax, 1 ; sys_write
	mov rdi, 1 ; stdout
	mov rsi, msg
	mov rdx, msglen
	syscall

	ret