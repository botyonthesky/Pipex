/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:54:12 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/04 14:55:32 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_create_pipe(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->n_cmd - 1)
	{
		if (pipe(data->pipe + 2 * i) == -1)
			ft_error(ft_put_error("Could not create pipe", "", "", 1), data);
		i++;
	}
}

int	ft_pipex(t_pipex *data)
{
	int	exit_code;

	if (pipe(data->pipe) == -1)
		ft_error(ft_put_error("pipe", ": ", strerror(errno), 1), data);
	data->child = 0;
	while (data->child < data->n_cmd)
	{
		data->cmd = ft_manage_cmd(data->argv[data->child + 2 + data->heredoc]);
		if (!data->cmd)
			ft_error(ft_put_error("Error on cmd", "", "", 1), data);
		data->cmd_path = ft_manage_path(data->cmd[0], data);
		data->pid[data->child] = fork();
		if (data->pid[data->child] == -1)
			ft_error(ft_put_error("fork", ": ", strerror(errno), 1), data);
		else if (data->pid[data->child] == 0)
			ft_child(data);
		ft_free_str(data->cmd_path, data->cmd);
		data->child++;
	}
	exit_code = ft_parent(data);
	if (data->heredoc == 1)
		unlink(".heredoc.tmp");
	return (exit_code);
}

t_pipex	ft_init_pipex(int argc, char **argv, char **envp)
{
	t_pipex		data;

	data = ft_init_data();
	data.envp = envp;
	data.argc = argc;
	data.argv = argv;
	if (ft_check_here_doc(argv[1]) == 1)
		data.heredoc = 1;
	ft_manage_fd_in(&data);
	ft_manage_fd_out(&data);
	data.n_cmd = argc - 3 - data.heredoc;
	data.pid = malloc(sizeof * data.pid * data.n_cmd);
	if (!data.pid)
		ft_error(ft_put_error("PID error", strerror(errno), "", 1), &data);
	data.pipe = malloc(sizeof * data.pipe * 2 * (data.n_cmd - 1));
	if (!data.pipe)
		ft_error(ft_put_error("Pipe error", "", "", 1), &data);
	ft_create_pipe(&data);
	return (data);
}
