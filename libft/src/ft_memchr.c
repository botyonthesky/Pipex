/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:31:01 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/13 14:34:07 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*x;
	unsigned char	y;
	size_t			i;

	x = (unsigned char *) s;
	y = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (x[i] == y)
			return (&x[i]);
	i++;
	}
	return (NULL);
}
