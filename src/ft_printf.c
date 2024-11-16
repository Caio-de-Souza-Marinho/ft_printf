/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:05 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/15 19:53:12 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_suite(char flag, va_list ap);

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += flag_suite(format[i + 1], ap);
			i++;
		}
		else
			count += ft_putchar_printf(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	flag_suite(char flag, va_list ap)
{
	int	count;

	count = 0;
	if (flag == 'c')
		count += ft_putchar_printf(va_arg(ap, int));
	return (count);
}
