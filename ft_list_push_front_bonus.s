section .text
	global	ft_list_push_front
	extern	malloc
	extern	__errno_location

	ft_list_push_front:			; void	ft_list_push_front(t_list **begin, void *data)
		push rdi
		push rsi
		mov rdi, 16				; struct is two pointers. Since we are on a x64 system, each of these pointers are 8 bytes (64 bits). Allocate 16 bytes.
		call malloc
		pop rsi
		pop rdi

		cmp rax, 0				; Couldn't allocate memory : return 0
		je malloc_fail

		mov [rax], rsi			; put data address in created space
		mov rcx, [rdi]			; address of previous first element in rcx
		mov [rax+8], rcx		; address of previous first element in "next" pointer of created structure
		mov [rdi], rax			; content of pointer to first element replaced with the address of the created element
		ret

	malloc_fail:
		mov r8, 12
		call __errno_location
		mov [rax], r8
		mov rax, 0
		ret
