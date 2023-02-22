/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:52:40 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/22 11:08:04 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	ft_close_all(t_data *data)
{
	if (data->pipefd1[0] != -1)
		ft_close(&data->pipefd1[0]);
	if (data->pipefd1[1] != -1)
		ft_close(&data->pipefd1[1]);
	if (data->pipefd2[0] != -1)
		ft_close(&data->pipefd2[0]);
	if (data->pipefd2[1] != -1)
		ft_close(&data->pipefd2[1]);
	if (data->fd_in != -1)
		ft_close(&data->fd_in);
	if (data->fd_out != -1)
		ft_close(&data->fd_out);
}

void	ft_close(int *fd)
{
	if (*fd == -1)
		return ;
	close(*fd);
	*fd = -1;
}

void	ft_free_dchar(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	ft_finish_f1_bis(t_data *data)
{
	ft_close_all(data);
	ft_free_dchar(data->paths);
	ft_free_dchar(data->param1);
}

void	ft_finish_f1(t_data *data, char **av)
{
	ft_not_found(av[2 + data->hd]);
	ft_close_all(data);
	ft_free_dchar(data->paths);
	ft_free_dchar(data->param1);
}
