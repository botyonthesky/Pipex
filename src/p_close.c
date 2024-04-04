/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_close.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:53:37 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/04 14:53:55 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_close_fd(t_pipex *data)
{
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	ft_close_pipe(data);
}

void	ft_close_pipe(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < (data->n_cmd - 1) * 2)
	{
		close(data->pipe[i]);
		i++;
	}
}
