/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:04:42 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 10:01:53 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne une chaîne
// de caractères représentant l’entier ’n’ reçu en
// argument. Les nombres négatifs doivent être gérés.

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		len_int;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_int = ft_intlen(n);
	output = ft_calloc(len_int + 1, sizeof(char));
	if (!output)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		output[0] = '-';
	}
	while (len_int && output[len_int - 1] != '-')
	{
		output[len_int - 1] = n % 10 + '0';
		n /= 10;
		len_int--;
	}
	return (output);
}

/*
int	main()
{
	char *str;

	str = ft_itoa(INT_MIN);
	printf("%s", str);
}*/