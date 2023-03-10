/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:33:12 by nvillase          #+#    #+#             */
/*   Updated: 2023/03/10 10:44:24 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <strings.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

# define FORMAT "cspdiuxX%"

int	ft_printf(const char *format, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int nb);

#endif