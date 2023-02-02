/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:22:04 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ajoute l’élément ’new’ au début de la liste.

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = (*alst);
	(*alst) = new;
}

/*
int	main()
{
	t_list elem1;
	t_list elem2;
	t_list *begin_list;

	char str[] = "Hey";
	char str2[] = "AAAA";
	elem1.content = str;
	elem2.content = str2;
	begin_list = &elem1;
	ft_lstadd_front(&begin_list, &elem2);
	

	
	printf("%s\n", (char *)begin_list->content);
	printf("%s", (char *)begin_list->next->content);
}*/