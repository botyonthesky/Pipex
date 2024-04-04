/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:52:08 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/04 14:52:10 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_replace_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\'')
		i++;
	if (str[i])
		i++;
	while (str[i] && str[i] != '\'')
	{
		if (str[i] == ' ')
			str[i] = -1;
		i++;
	}
	if (str[i])
		i++;
	if (str[i])
		ft_replace_space(str);
}

void	ft_restore_space(char **tab)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (tab[i])
	{
		str = tab[i];
		j = 0;
		while (str[j])
		{
			if (str[j] == -1)
				str[j] = ' ';
			j++;
		}
		i++;
	}
}

int	ft_check_space_backslash(char *str)
{
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(str);
	if (ft_strnstr_p(str, "' ", l) == 1
		|| ft_strnstr_p(str, " '", l) == 1)
		i = 1;
	if (ft_strnstr_p(str, "\\", l) == 1)
		i += 2;
	return (i);
}

char	*ft_remove_slash(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (result == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != '\\')
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}
