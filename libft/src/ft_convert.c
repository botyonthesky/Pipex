/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:19:20 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/13 14:20:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_convert(unsigned int x, char *set)
{
	static char	tmp[50];
	char		*new;
	int			set_len;

	set_len = ft_strlen(set);
	new = &tmp[49];
	*new = '\0';
	if (x == 0)
	{
		new--;
		*new = set[0];
	}
	else
	{
		while (x != 0)
		{
			if (new <= tmp)
				return (NULL);
			new--;
			*new = set[x % set_len];
			x /= set_len;
		}
	}
	return (new);
}
