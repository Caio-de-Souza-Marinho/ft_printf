/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:05 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/18 20:08:38 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier_process(char specifier, va_list ap);

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
			count += specifier_process(format[i + 1], ap);
			i++;
		}
		else
			count += ft_putchar_printf(format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

static int	specifier_process(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_printf(va_arg(ap, int), 1);
	else if (specifier == 's')
		count += ft_putstr_printf(va_arg(ap, char *), 1);
	else if (specifier == 'p')
		count += ft_putptr_printf(va_arg(ap, unsigned long), 1);
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr_printf(va_arg(ap, int), 1);
	else if (specifier == '%')
		count += ft_putchar_printf('%', 1);
	return (count);
}
