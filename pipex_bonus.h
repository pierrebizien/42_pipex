/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:01:03 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/07 14:13:17 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct	s_data
{
    int		pipefd2[2];
    int		pipefd1[2];
	int		fd_in;
	int		fd_out;
	char	**paths;
	int		npath1;
	int		npath2;
	char	**param1;
}				t_data;


//MAIN

char **ft_get_paths(char **envp);
char **ft_put_bs(char **paths);

//CLOSE
void	ft_close_all(t_data *data);
void	ft_close(int *fd);
void	ft_free_dchar(char **str);



//UTILS
void	ft_init(char **av, t_data *data, char**envp, int ac);
void	ft_first_fork(char **av, char **envp, t_data *data);




#endif