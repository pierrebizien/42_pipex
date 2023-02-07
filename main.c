/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:00:29 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/07 13:57:43 by pbizien          ###   ########.fr       */
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
	output = ft_calloc(ft_size_dchar(paths) + 1, sizeof(char *));
	if (!output)
		return (NULL);
	while (paths[i])
	{
		output[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	output[i] = NULL;
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
		return (-1);
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
	ft_init(av, &data, envp, ac);
	i = 2;
	pipe(data.pipefd1);
	id = fork();
	if (id == 0)
	{
		dup2(data.fd_in, 0);
		ft_close (&data.pipefd1[0]);
		dup2(data.pipefd1[1], 1);
		ft_close (&data.pipefd1[1]);
		data.param1 = ft_split(av[2], ' ');
		fprintf(stderr, " data param1 0 %s \n", data.param1[0]);
		fprintf(stderr, "EN  0 pipefd1 0 vaut %d et 1 vaut %d fd out vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out);
		ft_find_g_path(&data, data.param1, 1);
		execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
	}
	else
	{
		wait(NULL);
		ft_close(&data.fd_in);

		while (i - 2 < ac - 5)
		{
			if (i % 2 == 0)
			{
				fprintf(stderr, "ICI ON RENTRE 2 %d\n", id);
				pipe(data.pipefd2);
				id = fork();
				if (id == 0)
				{
				fprintf(stderr, "ICI ON RENTRE 2 BIS %d\n", id);
					data.param1 = ft_split(av[i + 1], ' ');
					fprintf(stderr, "pipefd1 2BIS 0 vaut %d et 1 vaut %d fd out vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out);
					fprintf(stderr, "pipefd2 2BIS 0 vaut %d et 1 vaut %d fd out vaut %d\n", data.pipefd2[0], data.pipefd2[1], data.fd_out);
					ft_find_g_path(&data, data.param1, 1);
					ft_close(&data.pipefd1[1]);
					dup2(data.pipefd1[0], 0);
					ft_close(&data.pipefd1[0]);
					ft_close(&data.pipefd2[0]);
					dup2(data.pipefd2[1], 1);
					ft_close(&data.pipefd2[1]);
					ft_close(&data.fd_out);
					fprintf(stderr, "TEST 2");
					execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
				}
				else
				{
					fprintf(stderr, "pipefd1 2 TER 0 vaut %d et 1 vaut %d fd out vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out);
					fprintf(stderr, "pipefd2 2 TER 0 vaut %d et 1 vaut %d fd out vaut %d\n", data.pipefd2[0], data.pipefd2[1], data.fd_out);
					ft_close(&data.pipefd1[1]);
					wait(NULL);
					ft_close(&data.pipefd1[0]);
					fprintf(stderr, "ICI ON RENTRE 2 TER %d\n", id);
				}
			}
			else
			{
				fprintf(stderr, "ICI ON RENTRE 3 %d\n", id);
				pipe(data.pipefd1);
				id = fork();
				if (id == 0)
				{
					fprintf(stderr, "ICI ON RENTRE 3 BIS %d\n", id);
					data.param1 = ft_split(av[i + 1], ' ');
					ft_find_g_path(&data, data.param1, 1);
					fprintf(stderr, "pipefd1 3BIS 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out, data.fd_in);
					fprintf(stderr, "pipefd2 3BIS 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd2[0], data.pipefd2[1], data.fd_out, data.fd_in);
					ft_close(&data.pipefd2[1]);
					dup2(data.pipefd2[0], 0);
					ft_close(&data.pipefd2[0]);
					ft_close(&data.pipefd1[0]);
					ft_close(&data.fd_out);
					dup2(data.pipefd1[1], 1);
					ft_close(&data.pipefd1[1]);
					execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
				}
				else
				{
					fprintf(stderr, "ON ENTRE 3 TER\n");
					fprintf(stderr, "pipefd1 3TER 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out, data.fd_in);
					fprintf(stderr, "pipefd2 3TER 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd2[0], data.pipefd2[1], data.fd_out, data.fd_in);
					ft_close(&data.pipefd2[1]);
					wait(NULL);
					ft_close(&data.pipefd2[0]);
				}
			}
			i++;
		}

		if (i % 2 == 0)
		{
			fprintf(stderr, "ICI ON RENTRE 4 %d\n", id);
			id = fork();
			if (id == 0)
			{
				fprintf(stderr, "pipefd1 4 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out, data.fd_in);
				fprintf(stderr, "pipefd2 4 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd2[0], data.pipefd2[1], data.fd_out, data.fd_in);
				dup2(data.pipefd1[0], 0);
				ft_close(&data.pipefd1[0]);
				dup2(data.fd_out, 1);
				data.param1 = ft_split(av[i + 1], ' ');
				fprintf(stderr, "PARAM vaut %s fd out vaut %d\n", data.param1[0], data.fd_out);
				ft_find_g_path(&data, data.param1, 1);
				ft_close(&data.fd_out);
				execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
			}
			else
			{
				wait(NULL);
				ft_free_dchar(data.paths);
				ft_close (&data.pipefd1[0]);
				ft_close(&data.fd_out);
			}
		}
		else
		{
			fprintf(stderr, "ICI ON RENTRE 5\n");
			fprintf(stderr, "pipefd1 5 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd1[0], data.pipefd1[1], data.fd_out, data.fd_in);
			fprintf(stderr, "pipefd2 5 0 vaut %d et 1 vaut %d fd out vaut %d et in vaut %d\n", data.pipefd2[0], data.pipefd2[1], data.fd_out, data.fd_in);
			id = fork();
			if (id == 0)
			{
				ft_close(&data.pipefd2[1]);
				dup2(data.pipefd2[0], 0);
				ft_close(&data.pipefd2[0]);
				dup2(data.fd_out, 1);
				fprintf(stderr, "HEEEEY fd.out vaut %d\n", data.fd_out);
				data.param1 = ft_split(av[i + 1], ' ');
				if (!data.param1)
					fprintf(stderr, "ERRRRRREUUUUUR\n");
				fprintf(stderr, "PARAM 5 vaut %s\n", data.param1[0]);
				ft_find_g_path(&data, data.param1, 1);
				ft_close(&data.fd_out);
				execve(ft_strjoin(data.paths[data.npath1], data.param1[0]), data.param1, envp);
			}
			else
			{
				ft_close(&data.pipefd2[1]);
				ft_close(&data.pipefd2[0]);
				ft_close(&data.fd_out);
				ft_free_dchar(data.paths);
				wait(NULL);
			}
		}
	}
	return (0);
}