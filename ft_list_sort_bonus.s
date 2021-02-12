section .text
	global ft_list_sort

	ft_list_sort:		; void ft_list_sort(t_list **begin, int (*cmp)())
		mov r13, [rdi]		; r13 = pointer on first element
		mov rdi, [rdi]		; rdi = pointer on first element
	
	main_loop:
		mov r10, [rdi+8]	; if elem->next == 0, return
		cmp r10, 0
		je return

		push rdi
		push rsi

		mov rcx, rsi		; rcx stores address of cmp function
		mov rsi, [rdi+8]	; rsi = elem->next
		mov rsi, [rsi]		; rsi = elem->next->data
		mov rdi, [rdi]		; rdi = elem->data
		call rcx			; call comparison function
		pop rsi				; restore registers
		pop rdi

		cmp rax, 0
		jg	sort_and_next
		jmp	next

	next:
		mov rdi, [rdi+8]	; elem = elem->next
		jmp main_loop
	
	sort_and_next:
		mov r11, [r10]		; r11 = elem->next->data
		mov r12, [rdi]		; r12 = elem->data
		mov [r10], r12		; elem->next->data = elem->data
		mov [rdi], r11		; elem->data = elem->next->data
		mov rdi, r13
		jmp main_loop

	return:
		ret

