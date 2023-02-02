/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:22:37 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Renvoie le dernier élément de la liste.

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int	main()
{
	t_list elem1;
	t_list elem2;
	t_list elem3;
	t_list elem4;
	t_list *begin_list;
	int		int1;

	int1 = 3;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	begin_list = &elem1;
	elem4.next = NULL;
	elem4.content = &int1;
	begin_list = ft_lstlast(begin_list);

	printf("%d\n", *((int *)begin_list->content));
}*/