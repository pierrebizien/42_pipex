/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/07 12:18:09 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(char **av, t_data *data, char**envp, int ac)
{
	data->paths = ft_get_paths(envp);
	data->paths = ft_put_bs(data->paths);
	data->fd_in = open(av[1], O_RDONLY, 00644);
	data->fd_out = open(av[ac - 1], O_RDWR | O_TRUNC , 00644);
	data->pipefd1[0] = -1;
	data->pipefd1[1] = -1;
	data->pipefd2[0] = -1;
	data->pipefd2[1] = -1;
}

// void	ft_first_fork(char **av, char **envp, t_data *data)
// {
// 		dup2(data.fd_in, 0);
// 		close (data.pipefd1[0]);
// 		dup2(data.pipefd1[1], 1);
// 		close (data.pipefd1[1]);
// 		data.param1 = ft_split(av[2], ' ');
// 		ft_find_g_path(&data, data.param1, 1);
// 		execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
// }

