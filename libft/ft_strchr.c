/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:00 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The strchr() function returns a pointer to the first occurrence of the 
//  character c in the string s.

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	value;
	char			*temp;

	value = (unsigned char)c;
	temp = (char *)s;
	i = 0;
	while (temp[i])
	{
		if (temp[i] == value)
		{
			return (temp + i);
		}
		i++;
	}
	if (c == 0)
		return (temp + i);
	return (NULL);
}

/*
int	main()
{
	char s[] = "tripouille";
	printf("%s\n", ft_strchr(s, 0));
	printf("%s\n", ft_strchr(s, 0));
}
*/