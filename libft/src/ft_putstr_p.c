/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:32:19 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/10 15:35:32 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr_p(char *str)
{
	if (str == NULL)
		return (ft_putstr_p("(null)"));
	if (str == 0)
		return (ft_putstr_p(NULL));
	return (write(1, str, ft_strlen(str)));
}
