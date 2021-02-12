section .text
	global ft_malloc_fails
	extern malloc
	extern __errno_location

	ft_malloc_fails:
		mov rdi, -3
		call malloc
		
		cmp rax, 0	;Si malloc a renvoyé NULL, on met errno à 12 (cannot allocate memory) et on retourne 0
		je error_exit
		ret

	error_exit:
		mov r8, 12
		call __errno_location
		mov [rax], r8
		mov rax, 0
		ret
