/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:57:40 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/05 14:04:55 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	new = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[k] = s1[i];
		i++;
		k++;
	}
	while (k < (ft_strlen(s1) + ft_strlen(s2)))
	{
		new[k] = s2[j];
		j++;
		k++;
	}
	new[k] = '\0';
	return (new);
}
