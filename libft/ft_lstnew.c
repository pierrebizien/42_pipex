/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:22:53 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et renvoie un nouvel
// élément. La variable membre ’content’ est
// initialisée à l’aide de la valeur du paramètre
// ’content’. La variable ’next’ est initialisée à
// NULL

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = ft_calloc(1, sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	return (ptr);
}

/*
int	main()
{
	t_list *ptr;
	char str[] = "Hey";

	ptr = ft_lstnew(str);
	printf("%s", (char *)ptr->content);
}*/