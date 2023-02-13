/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:39:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/13 13:29:29 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_heredoc(t_data *data)
{
	char *str;
	
	data->tmp_fd = open("tmp-file.txt", O_TRUNC | O_CREAT | O_RDWR);
	if (data->tmp_fd == -1)
		return (1);
	data->limiter = data->av[2];
	fprintf(stdout, "limiter vaut %s\n", data->limiter);
	write(1, "here_doc>", 10);
	str = get_next_line(0);
	write(data->tmp_fd, str, ft_strlen(str));
	while (ft_strncmp(data->limiter, str, ft_strlen(data->limiter)))
	{
		free(str);
		write(1, "here_doc>", 10);
		str = get_next_line(0);
		write(data->tmp_fd, str, ft_strlen(str));
		// fprintf(stdout, "comp vaut |%d| str vaut |%s| taille str |%zu| \n", ft_strncmp(str, data->limiter, ft_strlen(str)), str, ft_strlen(str));
	}
	free(str);
	ft_close(&data->tmp_fd);
	// data->tmp_fd = open("tmp-file.txt", O_RDWR | O_CREAT, 00777);
	// if (data->tmp_fd == -1)
	// {
	// 	fprintf(stderr, "FATAL ERROR\n");
	// 	return (1);
	// }
	data->tmp_fd = open("tmp-file.txt", O_RDWR);
	// char str2[20];
	// fprintf(stderr, "READ %zd\n", read(data->tmp_fd, str2, 20));
	// fprintf(stderr, "STR HEREDOC VAUT | %s |\n", str2);
	data->fd_in = data->tmp_fd;
	return (0);
}