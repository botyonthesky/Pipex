/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:44 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/04 14:53:23 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_manage_path(char *cmd, t_pipex *data)
{
	char	**path;
	char	*cmd_path;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	path = ft_get_path(data->envp);
	if (path == NULL)
		return (NULL);
	cmd_path = ft_get_cmd_path(cmd, path);
	if (cmd_path == NULL)
	{
		ft_put_error("command not found", ": ",
			data->argv[data->child + 2], 127);
	}
	ft_free_str(NULL, path);
	return (cmd_path);
}

char	**ft_get_path(char **envp)
{
	char		*envp_path;
	char		**path;

	envp_path = ft_get_envp_path(envp);
	if (envp_path == NULL)
		return (NULL);
	path = ft_split(envp_path, ':');
	ft_free_str(envp_path, NULL);
	if (path == NULL)
		return (NULL);
	path = ft_create_path(path);
	if (path == NULL)
		return (NULL);
	return (path);
}

char	**ft_create_path(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		ft_free_str(tmp, NULL);
		i++;
	}
	return (path);
}

char	*ft_get_envp_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i] != NULL && envp[i][0] != '\0')
	{
		path = ft_strnstr(envp[i], "PATH", 4);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			break ;
		}
		i++;
	}
	return (path);
}
