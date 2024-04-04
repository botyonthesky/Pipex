/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_memory_adress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:44:26 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/13 14:35:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_put_memory_adress(void *ptr)
{
	unsigned long	tmp;
	int				result;

	if (ptr == NULL)
		return (ft_putstr_p("(nil)"));
	tmp = (unsigned long)ptr;
	result = 0;
	if (tmp == 0)
		return (ft_putchar_p('0'));
	if (tmp > 15)
		result += ft_put_memory_adress((void *)(tmp / 16));
	result += ft_putchar_p("0123456789abcdef"[tmp % 16]);
	return (result);
}
