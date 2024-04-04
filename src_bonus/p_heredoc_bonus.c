/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_heredoc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:29:10 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/08 09:29:16 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

int	ft_check_here_doc(char *str)
{
	if (ft_strnstr_p(str, "here_doc", 8) == 1)
	{
		if (ft_strlen(str) == 8)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void	ft_here_doc(char **av)
{
	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	if (pipefd[0] == -1 || pipefd[1] == -1)
		ft_printf("Error on pipe\n");
	pid = fork();
	if (pid == -1)
		ft_printf("Error on fork\n");
	if (pid == 0)
		ft_apply_heredoc(pipefd, av);
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_apply_heredoc(int *pipefd, char **av)
{
	char	*line;

	close(pipefd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit (EXIT_SUCCESS);
		}
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
}

void	ft_manage_heredoc(t_pipex *data)
{
	int		tmp;
	int		stdin_fd;
	char	*line;

	tmp = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (tmp == -1)
		ft_error(ft_put_error("here_doc", ": ", strerror(errno), 1), data);
	line = "";
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (ft_strlen(data->argv[2]) + 1 == ft_strlen(line)
			&& !ft_strncmp(line, data->argv[2], ft_strlen(data->argv[2] + 1)))
			close(stdin_fd);
		else
			ft_putstr_fd(line, tmp);
		free(line);
	}
	close(tmp);
}
