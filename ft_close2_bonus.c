/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:35:20 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/09 15:08:16 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_finish_lf(t_data *data, char **av, int i)
{
	ft_not_found(av[i + 3]);
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

int	ft_end(t_data *data)
{
	int	error;

	ft_close_all(data);
	waitpid(data->last_pid, &error, 0);
	waitpid(-1, NULL, 0);
	ft_free_dchar(data->paths);
	if (error != 0)
		return (1);
	else
		return (0);
}

void	ft_not_found(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
}

void	ft_no_dir(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
}
