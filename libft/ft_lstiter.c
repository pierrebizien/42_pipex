/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:22:30 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Itère sur la liste ’lst’ et applique la fonction
// ’f’ au contenu chaque élément.

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void ft_print(void *arg)
{
	printf("%d\n",*((int *)arg));
}


int	main()
{
	t_list elem1;
	t_list elem2;
	t_list elem3;
	t_list elem4;
	t_list *begin_list;
	int		int1;
	int		int2;
	int		int3;
	int		int4;

	int1 = 3;
	int2 = 4;
	int3 = 5;
	int4 = 6;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	begin_list = &elem1;
	elem4.next = NULL;
	elem4.content = &int4;
	elem1.content = &int1;
	elem2.content = &int2;
	elem3.content = &int3;
	ft_lstiter(begin_list, ft_print);
}*/