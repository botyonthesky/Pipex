/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:17:50 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/23 17:15:41 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free_gnl(t_listg *stash)
{
	t_listg	*current;
	t_listg	*next;

	current = stash;
	while (current != NULL)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

void	ft_line_size(t_listg *stash, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
	stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return ;
}

t_listg	*ft_get_last(t_listg *stash)
{
	t_listg	*current;

	current = stash;
	while (current != NULL && current->next != NULL)
		current = current->next;
	return (current);
}

int	ft_is_newline(t_listg *stash)
{
	int		i;
	t_listg	*last_element;

	if (stash == NULL)
		return (0);
	last_element = ft_get_last(stash);
	i = 0;
	while (last_element->content[i])
	{
		if (last_element->content[i] == '\n')
			return (1);
	i++;
	}
	return (0);
}
