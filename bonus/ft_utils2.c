/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:45:16 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/21 11:04:35 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	ft_middle_even_child(t_data *data, int i)
{
	data->param1 = ft_split(data->av[i + 3 + data->hd], ' ');
	if (data->param1[0] == NULL)
	{
		ft_finish_lf(data, data->av, i);
		exit (1);
	}
	if (ft_find_g_path(data, data->param1, 1) == -1)
	{
		ft_finish_lf(data, data->av, i);
		exit (EXIT_FAILURE);
	}
	dup2(data->pipefd1[0], 0);
	ft_close(&data->pipefd1[0]);
	ft_close(&data->pipefd2[0]);
	dup2(data->pipefd2[1], 1);
	ft_exec(data);
}

void	ft_middle_even(t_data *data, int i)
{
	int	id;

	ft_close(&data->pipefd1[1]);
	pipe(data->pipefd2);
	id = fork ();
	if (id == 0)
	{
		ft_middle_even_child(data, i);
	}
	else
	{
		ft_close(&data->pipefd2[1]);
		ft_close(&data->pipefd1[0]);
	}
}

void	ft_middle_odd_child(t_data *data, int i)
{
	data->param1 = ft_split(data->av[i + 3 + data->hd], ' ');
	if (data->param1[0] == NULL)
	{
		ft_finish_lf(data, data->av, i);
		exit (1);
	}
	if (ft_find_g_path(data, data->param1, 1) == -1)
	{
		ft_finish_lf(data, data->av, i);
		exit (EXIT_FAILURE);
	}
	dup2(data->pipefd2[0], 0);
	ft_close(&data->pipefd2[0]);
	ft_close(&data->pipefd1[0]);
	dup2(data->pipefd1[1], 1);
	ft_exec(data);
}

void	ft_middle_odd(t_data *data, int i)
{
	int	id;

	ft_close(&data->pipefd2[1]);
	pipe(data->pipefd1);
	id = fork ();
	if (id == 0)
	{
		ft_middle_odd_child(data, i);
	}
	else
	{
		ft_close(&data->pipefd1[1]);
		ft_close(&data->pipefd2[0]);
	}
}

int	ft_middle(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ac - 5 - data->hd)
	{
		if (i % 2 == 0)
			ft_middle_even(data, i);
		else
			ft_middle_odd(data, i);
		i++;
	}
	return (i);
}
