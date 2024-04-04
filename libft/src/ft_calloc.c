/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:28:14 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/09 10:10:55 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	i;
	size_t	l;

	i = 0;
	l = nmemb * size;
	if (nmemb != 0 && l / nmemb != size)
		return (NULL);
	new = malloc(l);
	if (!new)
		return (NULL);
	if (size == 0)
		return (new);
	while (i < l)
	{
		((unsigned char *)new)[i] = 0;
		i++;
	}
	return (new);
}

/*#include <stdio.h>

int	main()
{
	int	i;

	i = 0;

	int	*ptr = (int*)ft_calloc(10, sizeof(int));

	if (ptr != NULL)
	{
		while (i < 10)
		{
			printf("%d\n", ptr[i]);
			i++;
		}
		free(ptr);
	}
	return (0);
}*/
