/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:22:45 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Itère sur la liste ’lst’ et applique la fonction
// ’f ’au contenu de chaque élément. Crée une nouvelle
// liste résultant des applications successives de
// ’f’. La fonction ’del’ est là pour détruire le
// contenu d’un élément si nécessaire

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*first;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp)
		{
			ft_lstadd_back(&first, temp);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
	}
	return (first);
}

/*
void *ft_f(void *a)
{
	*(int *)a *= 2;
	return (a);
}

void ft_del(void *a)
{
	(void)a;
}
int	main()
{
	t_list elem1;
	t_list elem2;
	t_list elem3;
	t_list elem4;
	t_list *begin_list;
	t_list *begin_list2;
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
	begin_list2 = ft_lstmap(begin_list, ft_f, ft_del);
	while (begin_list2)
	{
		printf("%d\n", *(int *)begin_list2->content);
		begin_list2 = begin_list2->next;
	}
	
	
}*/