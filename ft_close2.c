/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:35:20 by pbizien           #+#    #+#             */
/*   Updated: 2023/02/08 11:07:52 by pbizien          ###   ########.fr       */
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

int	ft_end(t_data *data)
{
	int	error;
	
	fprintf(stderr, "END\n");
	ft_close_all(data);
	while (1)
	{
		if (wait(&error) <= 0)
			break;
	}
	fprintf(stderr, "error vaut %d errno vaut %d\n", error, errno);
	ft_free_dchar(data->paths);
	if (error != 0)
		return (2);
	else 
		return (0);
}

