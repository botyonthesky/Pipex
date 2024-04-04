/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_child_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:27:55 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/08 09:27:59 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

void	ft_child(t_pipex *data)
{
	if (data->child == 0)
		ft_manage_fileno(data->fd_in, data->pipe[1], data);
	else if (data->child == data->n_cmd - 1)
		ft_manage_fileno(data->pipe[2 * data->child - 2], data->fd_out, data);
	else
		ft_manage_fileno(data->pipe[2 * data->child - 2],
			data->pipe[2 * data->child + 1], data);
	ft_close_fd(data);
	if (data->cmd == NULL || data->cmd_path == NULL)
		ft_error(1, data);
	if (execve(data->cmd_path, data->cmd, data->envp) == -1)
		ft_error(ft_put_error(data->cmd[0], ": ", strerror(errno), 1), data);
}
