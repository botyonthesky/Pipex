/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parent_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:28:26 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/08 09:28:28 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

int	ft_parent(t_pipex *data)
{
	pid_t	pid_wait;
	int		status;
	int		exit_code;

	ft_close_fd(data);
	data->child--;
	exit_code = 1;
	while (data->child >= 0)
	{
		pid_wait = waitpid(data->pid[data->child], &status, 0);
		if (pid_wait == data->pid[data->n_cmd - 1])
		{
			if ((data->child == (data->n_cmd - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		data->child--;
	}
	free(data->pipe);
	free(data->pid);
	if (data->cmd_path == NULL)
		exit_code = 127;
	return (exit_code);
}
