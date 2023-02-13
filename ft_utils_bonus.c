/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:18:33 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/13 10:57:24 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_init(char **av, t_data *data, char**envp, int ac)
{
	data->ac = ac;
	data->envp = envp;
	data->av = av;
	data->paths = ft_get_paths(envp);
	if (data->paths == NULL)
		return (fprintf(stderr, "erreur path\n"),1);
	data->paths = ft_put_bs(data->paths);
	if (ft_strncmp(av[1], "here_doc", 8) != 0)
		data->fd_in = open(av[1], O_RDONLY, 00644);
	data->fd_out = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 00644);
	if (data->fd_out == -1)
		return (fprintf(stderr, "erreur out\n"), ft_free_dchar(data->paths), ft_close(&data->fd_in),1);
	data->pipefd1[0] = -1;
	data->pipefd1[1] = -1;
	data->pipefd2[0] = -1;
	data->pipefd2[1] = -1;
	return (0);
}

void	ft_first_child(t_data *data, char **av, char **envp)
{
	if (data->fd_in == -1)
	{
		fprintf(stderr, "ERROR 1 FIRST\n");
		ft_free_dchar(data->paths);
		ft_close_all(data);
		exit (1);
	}
	data->param1 = ft_split(av[2], ' ');
	if (!data->param1[0])
	{
		fprintf(stderr, "ERROR 2 FIRST\n");
		ft_finish_f1_bis(data);
		exit(1);
	}
	if (ft_find_g_path(data, data->param1, 1) == -1)
	{
		fprintf(stderr, "ERROR 3 FIRST\n");
		ft_finish_f1(data, av);
		exit(1);
	}
	fprintf(stderr, "ICI GROS BG\n");
	dup2(data->fd_in, 0);
	// char str[10];
	// read(data->fd_in, str, 10);
	// fprintf(stderr, "INVAUT %s\n", str);
	ft_close(&data->pipefd1[0]);
	dup2(data->pipefd1[1], 1);
	ft_close(&data->pipefd1[1]);
	ft_close_all(data);
	execve(ft_strjoin(data->paths[data->npath1], data->param1[0]), \
		data->param1, envp);
}

void	ft_last_child(t_data *data, char **av, char **envp, int i)
{
	fprintf(stderr, "ON RENTRE EN LAST CHILD\n");
	data->param1 = ft_split(av[i + 3], ' ');
	if (data->param1[0] == NULL)
	{
		fprintf(stderr, "ERROR 1 LAST CHILD\n");
		ft_finish_lf_bis(data);
		exit (0);
	}
	if (ft_find_g_path(data, data->param1, 1) == -1)
	{
		fprintf(stderr, "ERROR 2 LAST CHILD\n");
		ft_finish_lf(data, av, i);
		exit (EXIT_FAILURE);
	}
	if (i % 2 == 0)
	{
		ft_close(&data->pipefd1[1]);
		dup2(data->pipefd1[0], 0);
		ft_close(&data->pipefd1[0]);
		
	}
	else
	{
		ft_close(&data->pipefd2[1]);
		dup2(data->pipefd2[0], 0);
		ft_close(&data->pipefd2[0]);
		
	}
	dup2(data->fd_out, 1);
	fprintf(stderr, " PARAM vaut %s", data->param1[0]);

	ft_close(&data->fd_out);
	ft_close_all(data);
	execve(ft_strjoin(data->paths[data->npath1], data->param1[0]), \
		data->param1, envp);
}

void	ft_print_fds(t_data *data)
{
	fprintf(stderr, "FD IN vaut %d\n", data->fd_in);
	fprintf(stderr, "FD OUT vaut %d\n", data->fd_out);
	fprintf(stderr, "PIPEFD1 1 vaut %d\n", data->pipefd1[1]);
	fprintf(stderr, "PIPEFD1 0 vaut %d\n", data->pipefd1[0]);
	fprintf(stderr, "PIPEFD2 1 vaut %d\n", data->pipefd2[1]);
	fprintf(stderr, "PIPEFD2 0 vaut %d\n", data->pipefd2[0]);
}

int	ft_main_suite(t_data *data, char **av, char **envp)
{
	int	id;
	int	i;

	pipe(data->pipefd1);
	id = fork();
	if (id == 0)
		ft_first_child(data, av, envp);
	else
	{
		ft_close(&data->fd_in);
		i = ft_middle(data);
		fprintf(stderr, "AFTER MIDDLE \n");
		ft_print_fds(data);
		data->last_pid = fork();
		if (data->last_pid == 0)
			ft_last_child(data, av, envp, i);
	}
	return (ft_end(data));
}
