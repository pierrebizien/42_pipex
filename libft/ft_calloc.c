/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:08 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The calloc() function allocates memory for an array of nmemb elements of size
//  bytes each and returns a pointer to the allocated memory. The memory is set 
//  to zero. If nmemb or size is 0, then calloc() returns either NULL, 
//  or a unique 
//  pointer value that can later be successfully passed to free(). 

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if ((nmemb == 0 || size == 0 || size > (SIZE_MAX / nmemb)))
		return (NULL);
	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}
/*
int	main()
{
	int *str;

	str = calloc(5, sizeof(int));
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	printf("%d", str[2]);
}
*/