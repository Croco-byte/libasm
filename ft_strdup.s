section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	extern __errno_location

	ft_strdup:		;char		*ft_strdup(const char *s);
		push rdi
		call ft_strlen
		inc rax
		mov rdi, rax
		call malloc
		
		cmp rax, 0	;Si malloc a renvoyé NULL, on met errno à 12 (cannot allocate memory) et on retourne 0
		je error_exit

		pop rdi
		mov rsi, rdi
		mov rdi, rax
		call ft_strcpy
		ret
	
	error_exit:
		mov r8, 12
		call __errno_location
		mov [rax], r8
		mov rax, 0
		ret




