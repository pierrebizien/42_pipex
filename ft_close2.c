/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:35:20 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/07 17:10:42 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_finish_lf(t_data *data, char **av)
{
	ft_not_found(av[4]);
	ft_close_all(data);
	ft_free_dchar(data->paths);
	ft_free_dchar(data->param1);
}

void	ft_finish_lf_bis(t_data *data)
{
	ft_close_all(data);
	ft_free_dchar(data->paths);
	ft_free_dchar(data->param1);
}

void	ft_end(t_data *data)
{
	ft_close(&data->fd_in);
	ft_close(&data->pipefd1[1]);
	wait(NULL);
	ft_free_dchar(data->paths);
	ft_close (&data->pipefd1[0]);
	ft_close(&data->fd_out);
}

