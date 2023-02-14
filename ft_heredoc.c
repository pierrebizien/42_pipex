/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:39:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/13 18:17:48 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_heredoc(t_data *data)
{
	char	*str;

	data->tmp_fd = open("tmp-file.txt", O_TRUNC | O_CREAT | O_RDWR, 00777);
	if (data->tmp_fd == -1)
		return (1);
	data->limiter = data->av[2];
	write(1, "here_doc>", 10);
	str = get_next_line(0);
	write(data->tmp_fd, str, ft_strlen(str));
	while (ft_strncmp(data->limiter, str, ft_strlen(data->limiter)))
	{
		free(str);
		write(1, "here_doc>", 10);
		str = get_next_line(0);
		write(data->tmp_fd, str, ft_strlen(str));
	}
	free(str);
	ft_close(&data->tmp_fd);
	data->tmp_fd = open("tmp-file.txt", O_RDWR);
	data->fd_in = data->tmp_fd;
	return (0);
}
