/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:28 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applique la fonction ’f’ à chaque caractère de la
// chaîne de caractères transmise comme argument,
// et en passant son index comme premier argument.
// Chaque caractère est transmis par adresse à ’f’
// afin d’être modifié si nécessaire

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!(*f))
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
