/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:05:55 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The  memcmp()  function returns an integer less than, equal to, or greater
//  than zero if the first n bytes of s1 is found, respec‐
//  tively, to be less than, to match, or be greater than the first 
//  n bytes of s2.
//  For a nonzero return value, the sign is determined by the sign of the 
//  difference between the first pair of bytes (interpreted  as
//  unsigned char) that differ in s1 and s2.
//  If n is zero, the return value is zero.

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (i < n - 1 && ptr_s1[i] == ptr_s2[i])
	{
		i++;
	}
	if (n == 0)
		return (0);
	return (ptr_s1[i] - ptr_s2[i]);
}

/*
int	main()
{
	char str[] = "Hello Pierre";
	char str2[] = "Hello Pierred";
	char s2[] = {0, 0, 124, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d",ft_memcmp(s2, s3, 4));
	printf("\n%d",memcmp(s2, s3, 4));
}*/
