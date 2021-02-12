section .test
	global ft_strcmp

	ft_strcmp:			; int	ft_strcmp(const char *s1, const char *s2);
		call compare
		movzx rax, al
		movzx r8, bl
		sub rax, r8
		jmp return

	compare:
		mov al, byte [rdi]
		mov bl, byte [rsi]
		
		cmp al, 0
		je return
		
		cmp bl, 0
		je return
		
		cmp al, bl
		jne return

		inc rdi
		inc rsi

		jmp compare

	return:
		ret
