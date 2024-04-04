/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:07:23 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/05 16:29:39 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*x;
	unsigned char		*y;

	i = 0;
	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (x[i] != y[i])
			return ((x[i] - y[i]));
	i++;
	}
	return (0);
}
