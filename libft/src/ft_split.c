/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:18:19 by tmaillar          #+#    #+#             */
/*   Updated: 2023/10/19 12:42:30 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_strndup(const char *src, size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	if (size == 0)
		return (NULL);
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**ft_free(char	**tab)
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

static size_t	ft_count(const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!new)
		return (NULL);
	while (s[i] && j < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != c && s[i])
			i++;
		new[j] = ft_strndup(&s[k], i - k);
		if (!new)
			return (ft_free(new));
		j++;
	}
	new[j] = NULL;
	return (new);
}
