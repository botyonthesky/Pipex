/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_error_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:28:10 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/08 09:28:15 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

void	ft_error(int error_stat, t_pipex *data)
{
	if (data)
	{
		ft_close_fd(data);
		if (data->pipe != NULL)
			free(data->pipe);
		if (data->pid != NULL)
			free(data->pid);
		if (data->cmd != NULL || data->cmd_path != NULL)
			ft_free_str(data->cmd_path, data->cmd);
	}
	if (data->heredoc == 1)
		unlink(".heredoc.tmp");
	exit(error_stat);
}

char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	ft_free_str(char *str, char **tab)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (tab != NULL)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

int	ft_put_error(char *str, char *str2, char *str3, int erno)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);
	return (erno);
}

int	ft_manage_error(int x)
{
	if (x == 1)
	{
		return (ft_put_error("Usage: ",
				"./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.",
				"", 1));
	}
	else
	{
		return (ft_put_error("Usage: ",
				"./pipex file1 cmd1 cmd2 ... cmdn file2.", "", 1));
	}
}
