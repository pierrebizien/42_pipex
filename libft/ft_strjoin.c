/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:11 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne une nouvelle
// chaîne, résultat de la concaténation de s1 et s2.

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*output;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	output = (char *)ft_calloc(len + 1, sizeof(char));
	if (output == NULL)
		return (NULL);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		output[j] = s2[i];
		i++;
		j++;
	}
	output[j] = '\0';
	return (output);
}

/*
int	main()
{
	char str[] = "Hello";
	char str2[] = "fff";
	char *output;

	output = ft_strjoin(str, str2);
	printf("%s", output);
}*/
