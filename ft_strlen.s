section .text
	global ft_strlen

	ft_strlen:		;size_t		ft_strlen(const char *s);

		xor rcx, rcx
		mov rax, rcx
		cmp rdi, 0
		je return
		call byte_loop
		mov rax, rcx
		ret
	
	byte_loop:
		cmp byte [rdi], 0
		je return
		inc rdi
		inc rcx
		jmp byte_loop

	return:
		ret



