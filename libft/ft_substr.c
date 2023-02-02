/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:09:15 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne une chaîne de
// caractères issue de la chaîne ’s’.
// Cette nouvelle chaîne commence à l’index ’start’ et
// a pour taille maximale ’len’

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		counter;

	counter = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (counter < len && s[counter + start])
	{
		str[counter] = s[counter + start];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

/*
int	main()
{
	char s[] = "Hello my friend";
	char *str;

	str = ft_substr(s, 3, 3);
	printf("%s", str);

}*/