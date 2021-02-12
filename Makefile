# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/07 15:38:57 by user42            #+#    #+#              #
#    Updated: 2021/02/12 16:03:43 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm
NAME_LIB = $(NAME).a

NASM = nasm
NASM_FLAGS = -f elf64

CC = clang
CC_FLAGS = -Wall -Werror -Wextra

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_malloc_fails.s
SRCS_BONUS = ft_atoi_base_bonus.s ft_list_push_front_bonus.s ft_list_size_bonus.s ft_list_sort_bonus.s ft_list_remove_if_bonus.s

OBJS = $(SRCS:.s=.o)
OBJS_BONUS = $(SRCS_BONUS:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME_LIB) $(OBJS)

%.o: %.s
			$(NASM) $(NASM_FLAGS) $< -o $@

bonus:		$(OBJS) $(OBJS_BONUS)
			ar rcs $(NAME_LIB) $(OBJS_BONUS) $(OBJS)

tests:
			$(CC) $(CC_FLAGS) main.c $(NAME_LIB) -o test

tests_bonus:
			$(CC) $(CC_FLAGS) main_bonus.c $(NAME_LIB) -o test

clean:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -f $(NAME_LIB)
			rm -f test

re:			fclean all
