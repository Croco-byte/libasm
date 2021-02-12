section .text
	global ft_read
	extern __errno_location

	ft_read:	;	ssize_t		ft_read(int fd, void *buf, size_t count);
		mov rax, 0
		syscall
		test rax, rax
		js exit_error
		jmp exit
	
	exit_error:
		neg rax
		mov r8, rax
		call __errno_location
		mov [rax], r8
		mov rax, -1
		ret
	
	exit:
		ret
