/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:48:08 by user42            #+#    #+#             */
/*   Updated: 2021/02/12 16:09:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/socket.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;

}				t_list;

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);
char		*ft_malloc_fails(void);

int			ft_atoi_base(char *str, char *base);
void		ft_list_push_front(t_list **begin, void *data);
int			ft_list_size(t_list *begin);
void		ft_list_sort(t_list **begin, int (*cmp)());
void		ft_list_remove_if(t_list **begin, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif
