/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:09:00 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strnstr() function locates the first occurrence of the null-terminated
// string little in the string big, where not more than len
// characters are searched.  Characters that appear after a ‘\0’ character 
// are not searched.  Since the strnstr() function is a
// FreeBSD specific API, it should only be used when portability is
// not a concern.

#include "libft.h"
#include <stdio.h>
//#include <bsd/string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	int		j;

	if (needle == NULL || ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		while (haystack [i + j] && needle[j] == haystack[i + j] && i + j < n)
		{
			j++;
			if (!needle[j])
			{
				return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	printf("%s\n", ft_strnstr("aaabcabcd", "cd", 8));
	//printf("%s", strnstr("", "aabc", -1));
}*/