/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_manage_fd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:27:22 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/08 09:27:25 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

void	ft_manage_fd_out(t_pipex *data)
{
	if (data->heredoc == 1)
		data->fd_out = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		data->fd_out = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
		ft_put_error(strerror(errno), ": ", data->argv[data->argc - 1], 1);
}

void	ft_manage_fd_in(t_pipex *data)
{
	if (data->heredoc == 1)
	{
		ft_manage_heredoc(data);
		data->fd_in = open(".heredoc.tmp", O_RDONLY);
		if (data->fd_in == -1)
			ft_error(ft_put_error("here_doc", ":", strerror(errno), 1), data);
	}
	else
	{
		data->fd_in = open(data->argv[1], O_RDONLY, 0644);
		if (data->fd_in == -1)
			ft_put_error(strerror(errno), ": ", data->argv[1], 1);
	}
}

void	ft_manage_fileno(int input, int output, t_pipex *data)
{
	if (dup2(input, STDIN_FILENO) == -1)
		ft_error(1, data);
	if (dup2(output, STDOUT_FILENO) == -1)
		ft_error(1, data);
}
