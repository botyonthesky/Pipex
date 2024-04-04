/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:35:41 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/12 15:42:44 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_p(int n)
{
	char	*new;
	int		len;

	len = 0;
	new = ft_itoa(n);
	len += ft_putstr_p(new);
	free(new);
	return (len);
}
