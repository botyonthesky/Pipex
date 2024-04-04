/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:09:45 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/13 14:18:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_short_p(va_list format)
{
	void	*ptr;

	ptr = va_arg(format, void *);
	if (ptr == NULL)
	{
		ft_putstr_p("(nil)");
		return (5);
	}
	else
	{
		ft_putstr_p("0x");
		return (ft_put_memory_adress(ptr) + 2);
	}
}

int	ft_short_u(va_list format)
{
	unsigned int	num;

	num = va_arg(format, unsigned int);
	if (num == 0)
	{
		ft_putchar_p('0');
		return (1);
	}
	else
		return (ft_putstr_p(ft_convert(num, "0123456789")));
}

int	ft_short_x(va_list format)
{
	unsigned int	numx;

	numx = va_arg(format, unsigned int);
	if (numx == 0)
	{
		ft_putchar_p('0');
		return (1);
	}
	else
		return (ft_putstr_p(ft_convert(numx, "0123456789abcdef")));
}

int	ft_short_gx(va_list format)
{
	unsigned int	numgx;

	numgx = va_arg(format, unsigned int);
	if (numgx == 0)
	{
		ft_putchar_p('0');
		return (1);
	}
	else
		return (ft_putstr_p(ft_convert(numgx, "0123456789ABCDEF")));
}

int	ft_check_char(char c, va_list format)
{
	if (c == 'c')
		return (ft_putchar_p(va_arg(format, int)));
	else if (c == 's')
		return (ft_putstr_p(va_arg(format, char *)));
	else if (c == 'p')
		return (ft_short_p(format));
	else if (c == 'd')
		return (ft_putnbr_p(va_arg(format, int)));
	else if (c == 'i')
		return (ft_putnbr_p(va_arg(format, int)));
	else if (c == 'u')
		return (ft_short_u(format));
	else if (c == 'x')
		return (ft_short_x(format));
	else if (c == 'X')
		return (ft_short_gx(format));
	else if (c == '%')
		return (ft_putchar_p('%'));
	return (0);
}
