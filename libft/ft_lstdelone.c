/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:22:22 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Libère la mémoire de l’élément passé en argument en
// utilisant la fonction ’del’ puis avec free(3). La
// mémoire de ’next’ ne doit pas être free

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
void	ft_del(void *to_del)
{
	*(int *)to_del = 0;
}


int	main()
{
	t_list *elem1;
	t_list *begin_list;

	elem1 = malloc(sizeof(t_list *));
	int int1 = 5;
	elem1->content = &int1;
	begin_list = elem1;
	printf("%d\n", *(int *)begin_list->content);
	ft_lstdelone(begin_list, ft_del);
	printf("%d\n", *(int *)begin_list->content);	
}*/