/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:05:48 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:53:48 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La fonction memchr() examine les n premiers octets de la zone mémoire 
// pointée par s à la recherche du caractère c. Le premier octet correspondant
// à c (interprété comme un unsigned char) arrête l'opération. 

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	value;
	unsigned char	*ptr_str;
	size_t			i;

	i = 0;
	value = (unsigned char)c;
	ptr_str = (unsigned char *)s;
	while (i < n)
	{
		if (ptr_str[i] == value)
		{
			return (ptr_str + i);
		}
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	char str[] = "Hello Pierre";
	char c;
	char *output;

	c = 'P';
	output = ft_memchr(str, c, sizeof(str));
	printf("%s", output);
}*/