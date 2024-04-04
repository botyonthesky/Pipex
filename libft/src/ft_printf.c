/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:21:49 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/13 14:22:20 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			len;

	va_start (args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_check_char(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar_p(format[i]);
	i++;
	}
	va_end(args);
	return (len);
}
