/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:55:56 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/04 14:56:25 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_strnstr_p(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return (0);
	if (big == NULL || little == NULL)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big [i + j] == little[j] && i + j < len)
			{
				if (little[j + 1] == '\0')
					return (1);
			j++;
			}
		}
	i++;
	}
	return (0);
}

void	ft_remove_quote(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\'')
		{
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
}

t_pipex	ft_init_data(void)
{
	t_pipex		data;

	data.envp = NULL;
	data.argv = NULL;
	data.pid = NULL;
	data.cmd = NULL;
	data.cmd_path = NULL;
	data.pipe = NULL;
	data.argc = -1;
	data.n_cmd = -1;
	data.child = -1;
	data.heredoc = 0;
	data.fd_in = -1;
	data.fd_out = -1;
	return (data);
}
