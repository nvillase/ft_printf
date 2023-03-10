/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:39:17 by nvillase          #+#    #+#             */
/*   Updated: 2023/03/10 17:27:08 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_format(va_list arg, char format)
{
	int	address;

	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (format == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'x' || format == 'X')
		return (ft_putexxx(va_arg(arg, unsigned long), format));
	if (format == 'p')
	{
		address = va_arg(arg, unsigned long);
		if (address <= 0)
			return (write(1, "(nil)", 5));
		return (write (1, "0x", 2) + ft_putexxx(address, 'x'));
	}
	return (0);
}

int	format_check(char format, va_list arg)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (FORMAT[++i])
	{
		if (format == FORMAT[i])
			count = apply_format(arg, FORMAT[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += format_check(format[i + 1], arg);
			if (format[i + 1])
				i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	return (count);
}
