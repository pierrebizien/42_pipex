/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/08 11:09:18 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init(char **av, t_data *data, char**envp, int ac)
{
	data->paths = ft_get_paths(envp);
	if (data->paths == NULL)
		return (1);
	data->paths = ft_put_bs(data->paths);
	data->fd_in = open(av[1], O_RDONLY, 00644);
	data->fd_out = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 00644);
	if (data->fd_out == -1)
		return (1);
	data->pipefd1[0] = -1;
	data->pipefd1[1] = -1;
	data->pipefd2[0] = -1;
	data->pipefd2[1] = -1;
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

void	ft_first_child(t_data *data, char **av, char **envp)
{
	fprintf(stderr, "FIRST\n");
	dup2(data->fd_in, 0);
	ft_close(&data->pipefd1[0]);
	dup2(data->pipefd1[1], 1);
	ft_close(&data->pipefd1[1]);
	data->param1 = ft_split(av[2], ' ');
	if (!data->param1[0])
	{
		ft_finish_f1_bis(data);
		exit(-1);
	}
	if (ft_find_g_path(data, data->param1, 1) == -1)
	{
		ft_finish_f1(data, av);
		exit(2);
	}
	ft_close_all(data);
	execve(ft_strjoin(data->paths[data->npath1], data->param1[0]), data->param1, envp);
}

void	ft_last_child(t_data *data, char **av, char **envp)
{
	fprintf(stderr, "LAST\n");
	ft_close(&data->fd_in);
	ft_close(&data->pipefd1[1]);
	dup2(data->pipefd1[0], 0);
	ft_close(&data->pipefd1[0]);
	dup2(data->fd_out, 1);
	ft_close(&data->fd_out);
	data->param1 = ft_split(av[3], ' ');
	if (data->param1[0] == NULL)
	{
		ft_finish_lf_bis(data);
		exit (0);
	}
	if (ft_find_g_path(data, data->param1, 1) == -1)
	{
		ft_finish_lf(data, av);
		exit (0);
	}
	ft_close_all(data);
	execve(ft_strjoin(data->paths[data->npath1], data->param1[0]), data->param1, envp);
}

int	ft_main_suite(t_data *data, char **av, char **envp)
{
	int id;
	
	pipe(data->pipefd1);
	id = fork();
	if (id == 0)
		ft_first_child(data, av, envp);
	else
	{
		id = fork();
		if (id == 0)
			ft_last_child(data, av, envp);
	}
	return (ft_end(data));
}
