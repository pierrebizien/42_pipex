/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:00:29 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/02 15:19:19 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char **ft_get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
		i++;
	}
	return (ft_split((envp[i] + 5), ':'));
	
}

int	ft_size_dchar(char **strstr)
{
	int	i;

	i = 0;
	while (strstr[i])
	{
		i++;
	}
	return (i);
}

char **ft_put_bs(char **paths)
{
	int	i;
	char **output;

	i = 0;
	output = ft_calloc(ft_size_dchar(paths), sizeof(char *));
	if (!output)
		return (NULL);
	while (paths[i])
	{
		output[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free (paths);
	return (output);
}

int	ft_find_g_path(t_data *data, char **param, int n)
{
	int	test;
	int	i;
	
	test = -1;
	i = -1;
	while (test == -1 && data->paths[++i])
	{
		test = access(ft_strjoin(data->paths[i], param[0]), F_OK);
	}
	if (test == -1)
		return (fprintf(stderr, "TEST VAUT -1"), -1);
	if (n == 1)
		data->npath1 = i;
	else
		data->npath2 = i;
	return (0);
}

int	main(int ac, char **av, char **envp)
{

	int		id;
	t_data	data;
	int		i;
		
	if (ac < 5)
		return (-1);
	data.paths = ft_get_paths(envp);
	data.paths = ft_put_bs(data.paths);
	data.fd_in = open(av[1], O_RDONLY, 00644);
	data.fd_out = open(av[ac - 1], O_RDWR | O_TRUNC , 00644);
	fprintf(stderr, "OUT vaut %d\n", data.fd_out);
	i = 2;
	pipe(data.pipefd1);
	id = fork();
	if (id == 0)
	{
		dup2(data.fd_in, 0);
		close (data.pipefd1[0]);
		dup2(data.pipefd1[1], 1);
		close (data.pipefd1[1]);
		data.param1 = ft_split(av[2], ' ');
		fprintf(stderr, " data param1 0 %s \n", data.param1[0]);
		ft_find_g_path(&data, data.param1, 1);
		execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
	}
	else
	{
		wait(NULL);
		while (i - 2 < ac - 5)
		{
			fprintf(stderr, "ICI ON RENTRE 1 \n");
			if (i % 2 == 0)	
			{
				fprintf(stderr, "ICI ON RENTRE 2 \n");
				pipe(data.pipefd2);
				id = fork();
				if (id == 0)
				{
					fprintf(stderr, "ICI ON RENTRE 2 BIS \n");
					data.param1 = ft_split(av[i + 1], ' ');
					ft_find_g_path(&data, data.param1, 1);
					close(data.pipefd1[1]);
					dup2(data.pipefd1[0], 0);
					close(data.pipefd1[0]);
					dup2(data.pipefd2[1], 1);
					close(data.pipefd2[0]);
					close(data.pipefd2[1]);
					execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
				}
			}
			else
			{
				fprintf(stderr, "ICI ON RENTRE 3 \n");
				pipe(data.pipefd1);
				id = fork();
				if (id == 0)
				{
					data.param1 = ft_split(av[i + 1], ' ');
					ft_find_g_path(&data, data.param1, 1);
					close(data.pipefd2[1]);
					dup2(data.pipefd2[0], 0);
					close(data.pipefd2[0]);
					dup2(data.pipefd1[1], 1);
					close(data.pipefd1[0]);
					close(data.pipefd1[1]);
					execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
				}
			}
			i++;
		}
		if (i % 2 == 0)
		{
			fprintf(stderr, "ICI ON RENTRE 4 \n");
			close(data.pipefd1[1]);
			dup2(data.pipefd1[0], 0);
			close(data.pipefd1[0]);
			close(data.pipefd2[0]);
			close(data.pipefd2[1]);
			dup2(data.fd_out, 1);
			data.param1 = ft_split(av[i + 1], ' ');
			ft_find_g_path(&data, data.param1, 1);
			execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
		}
		else
		{
			fprintf(stderr, "ICI ON RENTRE 5 \n");
			close(data.pipefd1[0]);
			close(data.pipefd1[1]);
			close(data.pipefd2[1]);
			char str[100];
			read(data.pipefd2[0], str, 10);
			fprintf(stderr, "pipefd2 0 vaut %s\n", str); 
			dup2(data.pipefd2[0], 0);
			close(data.pipefd2[0]);
			dup2(data.fd_out, 1);
			fprintf(stderr, "fd.out vaut %d\n", data.fd_out);
			data.param1 = ft_split(av[i + 1], ' ');
			if (!data.param1)
				fprintf(stderr, "ERRRRRREUUUUUR\n");
			fprintf(stderr, "PARAM vaut %s\n", data.param1[0]);
			ft_find_g_path(&data, data.param1, 1);
			execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
		}
	}
	return (0);
}