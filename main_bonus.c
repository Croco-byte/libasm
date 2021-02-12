/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:54:19 by user42            #+#    #+#             */
/*   Updated: 2021/02/12 16:02:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	check_atoi_base(void)
{
	printf("\n\n------------ ft_atoi_base tests -----------------\n");

	printf("1. Printing '7' in base 10 :			|%d|\n", ft_atoi_base("7", "0123456789"));
	printf("2. Printing '-15' in base 10 :			|%d|\n", ft_atoi_base("-15", "0123456789"));
	printf("3. Printing '0' in base 10 :			|%d|\n", ft_atoi_base("0", "0123456789"));
	printf("4. Printing '-0' in base 10 :			|%d|\n", ft_atoi_base("-0", "0123456789"));
	printf("5. Printing '452789' in base 10 :		|%d|\n", ft_atoi_base("452789", "0123456789"));
	printf("6. Printing '2147483647' in base 10 :		|%d|\n", ft_atoi_base("2147483647", "0123456789"));
	printf("7. Printing '2147483649' in base 10 :		|%d|\n", ft_atoi_base("2147483649", "0123456789"));
	printf("8. Printing '-2147483648' in base 10 :		|%d|\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("9. Printing '-2147483649' in base 10 :		|%d|\n", ft_atoi_base("-2147483649", "0123456789"));

	printf("10. Printing '7E' in base 16 :			|%d|\n", ft_atoi_base("7E", "0123456789ABCDEF"));
	printf("11. Printing 'FFFFFF' in base 16 :		|%d|\n", ft_atoi_base("FFFFFF", "0123456789ABCDEF"));

	printf("12. Printing '  +-7' in base 10 :		|%d|\n", ft_atoi_base("  +-7", "0123456789"));
	printf("13. Printing '  --147' in base 10 :		|%d|\n", ft_atoi_base("  --147", "0123456789"));
	printf("14. Printing '  ++14t7' in base 10 :		|%d|\n", ft_atoi_base("  ++14t7", "0123456789"));

	printf("15. Printing '1000' in base 2 :			|%d|\n", ft_atoi_base("1000", "01"));
	printf("16. Printing '-110000' in base 2 :		|%d|\n", ft_atoi_base("-110000", "01"));

	printf("17. Printing '5' with a wrong base :		|%d|\n", ft_atoi_base("5", "01123456789"));
	printf("18. Printing 'abcdef' in base 10 :		|%d|\n", ft_atoi_base("abcdef", "0123456789"));
	printf("19. Printing 'abc' in base 'bca' :		|%d|\n", ft_atoi_base("abc", "bca"));

	printf("20. Printing NULL in base 10 :			|%d|\n", ft_atoi_base(NULL, "0123456789"));
	printf("21. Printing '7' in base NULL :			|%d|\n", ft_atoi_base("7", NULL));
	printf("22. Printing NULL in base NULL :		|%d|\n", ft_atoi_base(NULL, NULL));
}

void	display_chained_list(t_list *begin)
{
	if (!begin)
	{
		printf("NULL\n");
		return ;
	}
	while (begin->next)
	{
		printf("%s --> ", (char *)begin->data);
		begin = begin->next;
	}
	printf("%s --> ", (char *)begin->data);
	printf("NULL\n");
}

void	check_list_push_front(void)
{

	printf("\n\n------------ ft_list_push_front tests -----------------\n");


	t_list *begin;
	t_list elem1;
	t_list elem2;
	t_list elem3;

	begin = &elem1;
	elem1.data = (void *)"[First element]";
	elem1.next = &elem2;
	elem2.data = (void *)"[Second element]";
	elem2.next = &elem3;
	elem3.data = (void *)"[Third element]";
	elem3.next = NULL;

	printf("\n1. Original chained list with three elements :\n");
	display_chained_list(begin);

	printf("\nAdding one element on the front :\n");
	char str[] = "[Added element]";
	ft_list_push_front(&begin, (void *)str);
	display_chained_list(begin);

	printf("\nAdding two more elements on the front :\n");
	char str2[] = "[One more ...]";
	char str3[] = "[Another ...]";
	ft_list_push_front(&begin, (void *)str2);
	ft_list_push_front(&begin, (void *)str3);
	display_chained_list(begin);

	printf("\n\n2. Trying to add to an empty chained list. Original list :\n");
	begin = 0;
	display_chained_list(begin);
	printf("\nAdding one element on the front :\n");
	ft_list_push_front(&begin, (void *)str);
	display_chained_list(begin);

}

void	check_ft_list_size(void)
{
	printf("\n\n------------ ft_list_size tests -----------------\n");


	t_list *begin;
	t_list elem1;
	t_list elem2;
	t_list elem3;

	begin = &elem1;
	elem1.data = (void *)"[First element]";
	elem1.next = &elem2;
	elem2.data = (void *)"[Second element]";
	elem2.next = &elem3;
	elem3.data = (void *)"[Third element]";
	elem3.next = NULL;

	printf("\n1. Original chained list with three elements :\n");
	display_chained_list(begin);
	printf("ft_list_size returns : |%d|\n", ft_list_size(begin));

	char str[] = "[Added element]";
	ft_list_push_front(&begin, (void *)str);
	printf("\nWith one more element :\n");
	display_chained_list(begin);
	printf("ft_list_size returns : |%d|\n", ft_list_size(begin));

	printf("\nNow with two more elements :\n");
	char str2[] = "[One more ...]";
	char str3[] = "[Another ...]";
	ft_list_push_front(&begin, (void *)str2);
	ft_list_push_front(&begin, (void *)str3);
	display_chained_list(begin);
	printf("ft_list_size returns : |%d|\n", ft_list_size(begin));

	printf("\n\n2. ft_list_size on an empty list :\n");
	begin = 0;
	display_chained_list(begin);
	printf("ft_list_size returns : |%d|\n", ft_list_size(begin));
}

void	check_list_sort(void)
{
		printf("\n\n------------ ft_list_sort tests -----------------\n\n");


	t_list *begin;
	t_list elem1;
	t_list elem2;
	t_list elem3;

	begin = &elem1;
	elem1.data = (void *)"[ZZZZ]";
	elem1.next = &elem2;
	elem2.data = (void *)"[AAAA]";
	elem2.next = &elem3;
	elem3.data = (void *)"[RRRR]";
	elem3.next = NULL;

	printf("1. Displaying the chained list before sorting by ft_strcmp :\n");
	display_chained_list(begin);
	printf("After sorting :\n");
	ft_list_sort(&begin, &ft_strcmp);
	display_chained_list(begin);

	t_list elem4;
	t_list elem5;

	elem1.data = (void *)"[8]";
	elem2.data = (void *)"[6]";
	elem3.data = (void *)"[4]";
	elem3.next = &elem4;
	elem4.data = (void *)"[2]";
	elem4.next = &elem5;
	elem5.data = (void *)"[0]";
	elem5.next = NULL;

	printf("\n2. Displaying the chained list before sorting by ft_strcmp :\n");
	display_chained_list(begin);
	printf("After sorting :\n");
	ft_list_sort(&begin, &ft_strcmp);
	display_chained_list(begin);
}

void free_fct(void *elem)
{
	free(elem);
}

void	check_list_remove_if(void)
{
	printf("\n\n------------ ft_list_remove_if tests -----------------\n\n");

	t_list *begin;
	t_list elem1;
	t_list elem2;
	t_list elem3;

	begin = &elem1;
	elem1.data = (void *)ft_strdup("1");
	elem1.next = &elem2;
	elem2.data = (void *)ft_strdup("1");
	elem2.next = &elem3;
	elem3.data = (void *)"3";
	elem3.next = NULL;

	printf("1. Displaying the chained list before removal :\n");
	display_chained_list(begin);
	printf("Removing all elements for which function ft_strcmp(\"1\", elem->data) returns 0 :\n");
	ft_list_remove_if(&begin, (void *)"1", &ft_strcmp, &free_fct);
	display_chained_list(begin);

	t_list elem4;
	t_list elem5;

	begin = &elem1;
	elem1.data = (void *)ft_strdup("Hi");
	elem1.next = &elem2;
	elem2.data = (void *)"Bonjour";
	elem2.next = &elem3;
	elem3.data = (void *)ft_strdup("Hi");
	elem3.next = &elem4;
	elem4.data = (void *)"Salut";
	elem4.next = &elem5;
	elem5.data = (void *)ft_strdup("Hi");
	elem5.next = NULL;

	printf("\n2. Displaying the chained list before removal :\n");
	display_chained_list(begin);
	printf("Removing all elements for which function ft_strcmp(\"Hi\", elem->data) returns 0 :\n");
	ft_list_remove_if(&begin, (void *)"Hi", &ft_strcmp, &free_fct);
	display_chained_list(begin);

	begin = &elem1;
	elem1.data = (void *)ft_strdup("Hi");
	elem1.next = NULL;
	printf("\n3. Displaying the chained list before removal :\n");
	display_chained_list(begin);
	printf("Removing all elements for which function ft_strcmp(\"Hi\", elem->data) returns 0 :\n");
	ft_list_remove_if(&begin, (void *)"Hi", &ft_strcmp, &free_fct);
	display_chained_list(begin);
}

int		main(void)
{

	check_atoi_base();
	check_list_push_front();
	check_ft_list_size();
	check_list_sort();
	check_list_remove_if();

	return (0);
}
