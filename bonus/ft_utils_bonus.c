/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/09 12:56:31 by pbizien          ###   ########.fr       */
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
