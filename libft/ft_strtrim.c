/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:09:09 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 10:42:40 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne une copie de
// la chaîne ’s1’, sans les caractères spécifiés
// dans ’set’ au début et à la fin de la chaîne de
// caractères.

#include "libft.h"
#include <stdio.h>

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	int				i;
	unsigned int	start;

	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	start = i;
	while (s1[i] && !ft_is_in_set(s1[i], set))
		i++;
	str = ft_calloc(i - start + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + start, i - start);
	return (str);
}

//bien penser à mettre char const dans la fonction du dessus 
//pour pouvoir appeler set sans cast
/*
int	main()
{
	char *str;

	str = ft_strtrim("   xxxtripouille   xxx", " x");
	printf("%s", str);
}*/