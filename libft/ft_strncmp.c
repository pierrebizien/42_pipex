/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:55 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  strcmp()  function compares the two strings s1 and s2.  The locale is 
// not taken into account (for a locale-aware comparison,
// see strcoll(3)).  It returns an integer less than, equal to, or 
// greater than zero if s1 is found, respectively, to be less  than,
// to match, or be greater than s2.

// The strncmp() function is similar, except it compares only the first 
// (at most) n bytes of s1 and s2.

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && i < n - 1)
	{
		i++;
	}
	if (n == 0)
		return (0);
	return (s1[i] - s2[i]);
}

/*
int main()
{
	printf("\n%d", ft_strncmp("1234", "1235", 3));
	printf("\n%d", strncmp("1234", "1235", 3));
}*/