/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:05 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/15 18:56:20 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...);
int	flag_suite(char flag);

int	ft_printf(const char *format, ...)
{
	int	count;
	int	i;
	va_list	ap;
	
	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		//if (format[i] == '%')
			//flag_suite(format[i + 1]);
		//else
			count += ft_putchar_printf(format[i]);
		i++;
	}
	return (count);
}

/*
int	flag_suite(char flag)
{
	int	count;

	count = 0;
	return (count);
}
*/
