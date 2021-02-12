section .text
	global ft_list_size

	ft_list_size:		; int ft_list_size(t_list *begin)
		xor rax, rax
		call list_loop
	
	list_loop:
		cmp rdi, 0
		je return
		mov rdi, [rdi+8]
		inc rax
		jmp list_loop



	return:
		ret
