/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:04:51 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memccpy()  function  copies no more than n bytes from memory area 
// src to memory area dest, stopping when the character c is
// found.

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	unsigned char	term_value;
	size_t			i;

	term_value = (unsigned char)c;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n && ptr_src[i] != term_value)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
}

/*
int main()
{

	int dest1[5] = {0};
	int	src[5] = {6,7,8,9,8000000};

	ft_memccpy(dest1, src, 257, sizeof(int) * 5);
	//memcpy(dest1, src, 5);

	printf("%d ", dest1[0]);
	printf("%d ", dest1[1]);
	printf("%d ", dest1[2]);
	printf("%d ", dest1[3]);
	printf("%d ", dest1[4]);

}*/