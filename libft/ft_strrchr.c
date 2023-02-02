/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:09:05 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strrchr() function returns a pointer to the last occurrence of the 
// character c in the string s.

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				index;
	char			*temp;
	unsigned char	value;

	i = 0;
	temp = (char *)s;
	value = (unsigned char)c;
	index = -1;
	while (temp[i])
	{
		if (temp[i] == value)
		{
			index = i;
		}
		i++;
	}
	if (c == 0)
		return (temp + i);
	if (index > -1)
		return (temp + index);
	return (NULL);
}

/*
int	main()
{
	char s[] = "tripouille";

	printf("%s", ft_strrchr(s, 't' + 256));
	printf("%s", strrchr(s, 't' + 256));
}*/