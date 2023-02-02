/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:09:38 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:15 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*
int	main()
{
	int	c;

	c = 'z';
	char s[] = "tripouille";

	printf("Réelle %d \n", toupper(c));
	printf("Moi %d ", ft_toupper(c));
}*/