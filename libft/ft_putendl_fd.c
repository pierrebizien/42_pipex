/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:07:01 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 09:32:31 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Écrit La chaîne de caractères ’s’ sur le
// descripteur de fichier donné suivie d’un retour à
// la ligne

#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*
int	main()
{
	int	fd;

	fd = open("test.txt", O_WRONLY);
	//printf("%d", fd);
	ft_putendl_fd("Nouvelle ligne après ça", fd);
	ft_putendl_fd("Nouvelle ligne après ça", fd);
	close(fd);
}*/