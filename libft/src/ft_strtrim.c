/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:06:47 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/05 14:11:17 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_check(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
	i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check(set, s1[start]))
		start++;
	while (end > start && ft_check(set, s1[end - 1]))
		end--;
	new = malloc(sizeof(char) * ((end - start) + 1));
	if (!new)
		return (NULL);
	while (start < end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
// int	main()
// {
// 	char	x[] = "--------la botte secrete de perceval--------";
// 	char	y[] = "-";

// 	printf("%s\n", ft_strtrim(x, y));

// 	return (0);
// }
