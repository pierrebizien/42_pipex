/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/07 17:54:25 by pbizien          ###   ########.fr       */
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

void	ft_first_fork(t_data *data, char **av, char **envp)
{
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
	execve(ft_strjoin(data->paths[data->npath1], data->param1[0]), data->param1, envp);
}

void	ft_last_fork(t_data *data, char **av, char **envp)
{
	ft_close(&data->fd_in);
	ft_close(&data->pipefd1[1]);
	dup2(data->pipefd1[0], 0);
	ft_close(&data->pipefd1[0]);
	dup2(data->fd_out, 1);
	ft_close(&data->fd_out);
	data->param1 = ft_split(av[3], ' ');
	// fprintf(stderr, "av vaut %s fd out vaut %d\n", av[3], data->fd_out);
	if (data->param1[0] == NULL)
	{
		ft_finish_lf_bis(data);
		exit (-1);
	}
	if (ft_find_g_path(data, data->param1, 1) == -1)
	{
		ft_finish_lf(data, av);
		exit(2);
	}
	execve(ft_strjoin(data->paths[data->npath1], data->param1[0]), data->param1, envp);
		
}

int	ft_main_suite(t_data *data, char **av, char **envp)
{
	int error;
	int id;
	
	pipe(data->pipefd1);
	id = fork();
	if (id == 0)
		ft_first_fork(data, av, envp);
	else
	{
		wait(&error);
		if (error != 0)
			return (ft_free_dchar(data->paths), ft_close(&data->fd_in), \
				ft_close(&data->fd_out), ft_close(&data->pipefd1[1]), \
					ft_close(&data->pipefd1[0]), 1);
		id = fork();
		if (id == 0)
			ft_last_fork(data, av, envp);
		else
			ft_end(data);
	}
	return (0);
}

// fprintf(stderr, "pipefd1 4 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out, data.fd_in);
			// fprintf(stderr, "pipefd2 4 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd2[0], data.pipefd2[1], data.fd_out, data.fd_in);
			// ft_close(&data.pipefd1[1]);
			// dup2(data.pipefd1[0], 0);
			// ft_close(&data.pipefd1[0]);
			// dup2(data.fd_out, 1);
			// ft_close(&data.fd_out);
			// data.param1 = ft_split(av[3], ' ');
			// fprintf(stderr, "av vaut %s fd out vaut %d\n", av[i + 1], data.fd_out);
			// if (data.param1[0] == NULL || ft_find_g_path(&data, data.param1, 1) == -1)
			// 	return (ft_not_found(av[3]), ft_close_all(&data), ft_free_dchar(data.paths), ft_free_dchar(data.param1), 1);
			// execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);