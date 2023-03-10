/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:39:17 by nvillase          #+#    #+#             */
/*   Updated: 2023/03/10 10:41:13 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (format[i] == "%" && format[i + 1])
		{
			count += format_check(format[i + 1], arg);
		}
		else
		{
			write(1, format[i], 1);
		}
	}	
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

int	apply_format(va_list arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, char *)));
	if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (format == 'd')
		return (ft_putnbr(va_arg(arg, char *)));
	if (format == 'u')
		return (ft_putnbr(va_arg(arg, char *)));
	if (format == '%')
		return (write(1, '%', 1), 1);
	if (format == 'i')
		return (ft_putnbr(va_arg(arg, char *)));
}
