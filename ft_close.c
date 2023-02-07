/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:52:40 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/07 13:32:22 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_all(t_data *data)
{
	close(data->pipefd1[0]);
	close(data->pipefd1[1]);
	close(data->pipefd2[0]);
	close(data->pipefd2[1]);
	close(data->fd_in);
	close(data->fd_out);
}

void	ft_close(int *fd)
{
	close(*fd);
	*fd = -1;
}

void	ft_free_dchar(char **str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}