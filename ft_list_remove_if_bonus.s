section .text
	global ft_list_remove_if

	ft_list_remove_if:		; void ft_list_remove_if (t_list **begin, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
							; rdi = begin - rsi = data_ref - rdx = cmp - rcx = free_fct

	first_loop:
		mov r10, [rdi]		; r10 = first element elem
		cmp r10, 0
		je skip
		push rdi
		push rsi
		push rdx
		push rcx

		mov rdi, [r10]	; rdi = elem->data (rsi = data_ref)
		call rdx
		
		pop rcx
		pop rdx
		pop rsi
		pop rdi
		
		cmp rax, 0
		jne skip		; First element isn't to be deleted. Skipping.

	delete_first:
		push rdi
		push rsi
		push rdx
		push rcx

		mov rdi, [r10]		; rdi = elem->data
		call rcx			; free elem->data
		
		pop rcx
		pop rdx		
		pop rsi
		pop rdi
		
		mov r10, [rdi]		; r10 = first element elem
		mov r11, [r10+8]	; r11 = elem->next
		mov [rdi], r11		; elem = elem->next
		jmp first_loop

	skip:
		mov r10, [rdi]		; r10 = first element elem

	second_loop:
		cmp r10, 0
		je return
		mov r11, [r10+8]	; r11 = elem->next
		cmp r11, 0
		je return

		push r10
		push r11
		push rdi
		push rsi
		push rdx
		push rcx

		mov rdi, [r11]
		call rdx

		pop rcx
		pop rdx
		pop rsi
		pop rdi
		pop r11
		pop r10

		cmp rax, 0
		jne pass
	
	delete:
		push r10
		push r11
		push rdi
		push rsi
		push rdx
		push rcx

		mov rdi, [r11]		; rdi = elem->next->data
		call rcx

		pop rcx
		pop rdx
		pop rsi
		pop rdi
		pop r11
		pop r10

		mov r11, [r11+8]	; r11 = elem->next->next
		mov [r10+8], r11	; elem->next = elem->next->next
		jmp second_loop

	pass:
		mov r10, r11	; elem = elem->next
		jmp second_loop

	return:
		ret
