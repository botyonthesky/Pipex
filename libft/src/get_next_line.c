/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:01:02 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/23 17:14:17 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*get_next_line(int fd)
{
	static t_listg	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	ft_read_and_store_data(fd, &stash);
	if (!stash)
		return (NULL);
	ft_build_final_line(stash, &line);
	ft_clean(&stash);
	if (line[0] == '\0')
	{
		ft_free_gnl(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read_and_store_data(int fd, t_listg **stash)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_is_newline(*stash) && bytes_read > 0)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tmp)
			return ;
		bytes_read = (int)read(fd, tmp, BUFFER_SIZE);
		if ((*stash == NULL && bytes_read == 0) || bytes_read == -1)
		{
			free(tmp);
			return ;
		}
		tmp[bytes_read] = '\0';
		ft_insert_to_stash(stash, tmp, bytes_read);
		free(tmp);
	}
}

void	ft_insert_to_stash(t_listg **stash, char *tmp, int bytes_read)
{
	int		i;
	t_listg	*last_element;
	t_listg	*new;

	new = malloc(sizeof(t_listg));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * bytes_read + 1);
	if (new->content == NULL)
		return ;
	i = 0;
	while (tmp[i] && i < bytes_read)
	{
		new->content[i] = tmp[i];
		i++;
	}
	new->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	last_element = ft_get_last(*stash);
	last_element->next = new;
}

void	ft_build_final_line(t_listg *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	ft_line_size(stash, line);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	ft_clean(t_listg **stash)
{
	t_listg	*last;
	t_listg	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (clean == NULL || stash == NULL)
		return ;
	clean->next = NULL;
	last = ft_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content != NULL && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char)
			* (ft_strlen_gnl(last->content) - i + 1));
	if (clean->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	ft_free_gnl(*stash);
	*stash = clean;
}
