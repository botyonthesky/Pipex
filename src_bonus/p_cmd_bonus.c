/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:27:06 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/08 09:27:09 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

char	**ft_manage_cmd(char *av)
{
	char	**cmd;

	cmd = NULL;
	if (ft_check_space_backslash(av) > 0)
		cmd = ft_manage_space(av);
	else
		cmd = ft_split(av, ' ');
	return (cmd);
}

char	**ft_manage_space(char *av)
{
	char	**cmd;

	cmd = NULL;
	if (ft_check_space_backslash(av) == 1)
	{
		ft_replace_space(av);
		ft_remove_quote(av);
		cmd = ft_split(av, ' ');
		ft_restore_space(cmd);
	}
	else if (ft_check_space_backslash(av) == 2)
	{
		av = ft_remove_slash(av);
		cmd = ft_split(av, ' ');
	}
	else if (ft_check_space_backslash(av) == 3)
	{
		av = ft_remove_slash(av);
		ft_replace_space(av);
		ft_remove_quote(av);
		cmd = ft_split(av, ' ');
		ft_restore_space(cmd);
	}
	return (cmd);
}

char	*ft_get_cmd_path(char *cmd, char **path)
{
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (cmd_path == NULL)
		{
			ft_free_str(NULL, path);
			ft_error(ft_put_error("UB", "", "", 1), NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		ft_free_str(cmd_path, NULL);
		i++;
	}
	return (NULL);
}
