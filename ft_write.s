section .text
	global ft_write
	extern __errno_location

	ft_write:		;ssize_t ft_write(int fd, const void *buf, size_t count)
		mov rax, 1
		syscall
		test rax, rax	;this instruction allows us to know if rax (return value of syscall) is negative. If yes, there was an error.
		js exit_error
		jmp exit

	exit_error:
		neg rax			;after a syscall error, rax is a negative value and errno adopts the positive version of this value. So we reverse rax...
		mov r8, rax		;and we store it in r8.
		call __errno_location	;we call __errno_location, that stores in rax a pointer to the location of errno
		mov [rax], r8		;we put the saved value of errno in the location pointed by rax (errno)
		mov rax, -1			;we return -1 since write failed
		ret

	exit:
		ret

