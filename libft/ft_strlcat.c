/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:18 by pbizien           #+#    #+#             */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}
