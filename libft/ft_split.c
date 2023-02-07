/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:51 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/07 13:20:25 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne un tableau
// de chaînes de caractères obtenu en séparant ’s’ à
// l’aide du caractère ’c’, utilisé comme délimiteur.
// Le tableau doit être terminé par NULL

#include "libft.h"
#include <stdio.h>

static int	ft_nb_mots(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != 0)
		count++;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_nb_char_to_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_generate(char const *s, char c)
{
	int		i;
	int		len;
	char	*output;

	i = 0;
	len = ft_nb_char_to_c(s, c);
	output = ft_calloc(len + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (s[i] != c && s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len_mots;
	char	**output;
	int		y;

	i = 0;
	y = 0;
	len_mots = ft_nb_mots(s, c);
	output = ft_calloc(len_mots + 1, sizeof(char *));
	if (!output)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			output[y++] = ft_generate(s + i, c);
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	output[y] = NULL;
	return (output);
}

/*
int	main()
{
	char str[] = "Hello my friend";
	char c = ' ';
	char **output;

	output = ft_split(str, c);
	printf("%s", output[1]);
	free(output[0]);
	free(output[1]);
	free(output[2]);
	free(output);
}*/