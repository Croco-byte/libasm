section .text
	global ft_atoi_base
	extern ft_strlen

	ft_atoi_base:		; int	ft_atoi_base(char *str, char *base)
		
		;; Checking arguments
		mov rax, 0
		cmp rdi, 0
		je done
		cmp rsi, 0
		je done

		;; Checking base characters
		push rdi
		push rsi
		mov rdi, rsi
		call check_base
		pop rsi
		pop rdi
		mov r11, 0		; number = 0
		mov r12, 1		; sign = 1
		cmp rax, 0
		je end

		;; Checking base length
		push rdi
		push rsi
		mov rdi, rsi
		call ft_strlen
		pop rsi
		pop rdi
		cmp rax, 2
		jl end

		mov r10, rax	; r10 : base_size
		dec rdi

	skip_space:
		inc rdi
		mov bl, byte [rdi]
		cmp bl, 9
		je skip_space
		cmp bl, 10
		je skip_space
		cmp bl, 11
		je skip_space
		cmp bl, 12
		je skip_space
		cmp bl, 13
		je skip_space
		cmp bl, 32
		je skip_space
		dec rdi
	
	skip_sign:
		inc rdi
		mov bl, byte [rdi]
		cmp bl, 43
		je skip_sign
		cmp bl, 45
		je change_sign

	main_loop:
		push rdi
		push rsi
		mov dil, byte [rdi] ; dil = str[i], rsi = base
		call in_str
		pop rsi
		pop rdi
		cmp rax, 0
		jl end
		imul r11, r10
		add r11, rax
		inc rdi
		jmp main_loop
	
	in_str:
		mov rax, -1
	in_str_loop:
		inc rax
		mov bl, byte [rsi+rax]
		cmp bl, 0
		je not_found
		cmp bl, dil
		je found
		jmp in_str_loop

	not_found:
		mov rax, -1
		ret
	found:
		ret





	check_base:
		mov rax, 0		; ret = 0
		mov r11, 0		; i = 0
		mov r12, 0		; j = 0
	whilei:
		mov sil, byte [rdi+r11] ; sil = base[i]
		cmp sil, 0				; ending while loop
		je donei				; returning 1

		cmp sil, 43				; if a char in the base is '+', '-', or non-printable,
		je done					; return 0
		cmp sil, 45
		je done
		cmp sil, 33
		jl done
		cmp sil, 127
		jg done

		mov r12, r11
		inc r12					; j = i + 1
	whilej:
		mov bl, byte [rdi+r12]	; bl = base[j]
		cmp bl, 0
		je donej

		cmp sil, bl
		je done
		inc r12
		jmp whilej
	donej:
		inc r11
		jmp whilei
	donei:
		mov rax, 1
	done:
		ret

	change_sign:
		imul r12, -1
		jmp skip_sign

	end:
		imul r11, r12	; number = number * sign
		mov rax, r11
		ret
