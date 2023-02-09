/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:00:29 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/09 16:42:48 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
		i++;
	}
	if (i == ft_size_dchar(envp))
		return (NULL);
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

char	**ft_put_bs(char **paths)
{
	int		i;
	char	**output;

	i = 0;
	output = ft_calloc(ft_size_dchar(paths) + 2, sizeof(char *));
	if (!output)
		return (NULL);
	while (paths[i])
	{
		output[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	output[i] = ft_strdup("");
	output[i + 1] = NULL;
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
	int		test;
	int		i;
	char	*str;

	test = -1;
	i = -1;
	while (test == -1 && data->paths[++i])
	{
		str = ft_strjoin(data->paths[i], param[0]);
		// fprintf(stderr, "STR VAUT %s\n", str);
		test = access(str, F_OK);
		free(str);
	}
	if (test == -1)
		return (perror("ICI"), -1);
	if (n == 1)
		data->npath1 = i;
	else
		data->npath2 = i;
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5 || (ac < 6 && av[1] == "here_doc"))
		return (/*ft_putstr_fd("Nombre d'arguments invalide\n", 2)*/ 1);
	if (ft_init(av, &data, envp, ac) != 0)
		return (1);
	if (av[1] == "here_doc")
		ft_heredoc(&data);
	if (data.fd_in == -1)
		ft_no_dir(av[1]);
	return (ft_main_suite(&data, av, envp));
}
