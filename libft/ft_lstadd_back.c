/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:21:57 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ajoute l’élément ’new’ à la fin de la liste

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*begin_list;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	begin_list = ft_lstlast(*alst);
	begin_list->next = new;
}

/*
int	main()
{
	t_list elem1;
	t_list elem2;
	t_list elem3;
	t_list *begin_list;

	char str[] = "Hey";
	char str2[] = "AAAA";
	char str3[] = "BBBB";
	elem1.content = str;
	elem2.content = str2;
	elem3.content = str3;
	elem2.next = NULL;
	elem1.next = &elem2;
	begin_list = &elem1;
	ft_lstadd_back(&begin_list, &elem3);
	while (begin_list)
	{
		printf("%s", (char *)begin_list->content);
		begin_list = begin_list->next;
	}
}*/