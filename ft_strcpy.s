section .text
	global ft_strcpy

	ft_strcpy:		;char * ft_strcpy(char *dest, char *src)
		
		;; Start with RAX = 0. If either of the parameters are NULL, return.
		mov rax, 0
		cmp rdi, 0
		je return
		cmp rsi, 0
		je return	

		;; Save the address of destination buffer on the stack.
		push rdi
	

		;; Call copy function
		call copy
		
		;; Ends the destination with the final \0 of the source, put the pointer to the destination in rax, then return.
		movsb
		pop rax
		jmp return


	copy:
		cmp byte [rsi], 0
		je return
		movsb
		jmp copy

	return:
		ret

