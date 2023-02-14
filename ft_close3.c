/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:42:16 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/13 18:43:56 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_if(int *fd, t_data *data)
{
	if (data->hd == 0)
	{
		close(*fd);
		*fd = -1;
	}
}

int	ft_create_out(t_data *data)
{
	if (data->hd == 0)
	{
		data->fd_out = open(data->av[data->ac - 1], O_RDWR \
			| O_TRUNC | O_CREAT, 00644);
	}
	else
	{
		data->fd_out = open(data->av[data->ac - 1], O_RDWR \
			| O_APPEND | O_CREAT, 00644);
	}
	if (data->fd_out == -1)
		return (1);
	else
		return (0);
}

void	ft_kill_lc(t_data *data)
{
	ft_close_all(data);
	ft_free_dchar(data->paths);
	return ;
}

void	ft_wait(void)
{
	while (1)
	{
		if (wait(NULL) <= 0)
			break ;
	}
}
