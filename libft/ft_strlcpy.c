/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:25 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The strlcpy() and strlcat() functions copy and concatenate strings 
// respectively.  They are designed to be safer, more consistent,
// and less error prone replacements for strncpy(3) and strncat(3).  
// Unlike those functions, strlcpy() and strlcat() take the full
// size of the buffer (not just the length) and guarantee to NUL-terminate 
// the result (as long as size is larger than 0 or, in the
// case of strlcat(), as long as there is at least one byte free in dst).  
// Note that a byte for the NUL should be included in size.
// Also note that strlcpy() and strlcat() only operate on true “C” strings. 
// This means that for strlcpy() src must be NUL-terminated
// and for strlcat() both src and dst must be NUL-terminated.

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1 < n))
	{
		dst[i] = src[i];
		i++;
	}
	if (n > 0)
	{
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	while (src[count] != '\0')
		++count;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
*/

/*
int main()
{
	char src[] = "coucou";
	char dest[10]; ft_memset(dest, 'A', 10);
	printf("%ld\n", ft_strlcpy(dest, src, 2));
	printf("%c\n",dest[0]);
	int a;
	if (dest[0] == 'A')
		a = 32;
	printf("%d\n", a);
	printf("%c\n",dest[1]);
	printf("%c\n",dest[2]);

}*/