/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:05 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/20 20:55:10 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	init_data(t_data *data, const char *format);

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data, format))
		return (-1);
	while (*data.s != '\0')
	{
		if (*data.s == '%' && *(data.s++))
		{
			if (parse_format(&data))
			{
				return (-1);
			}
			render_format(&data);
		}
		else
		{
			write_buffer(&data, *data.s);
		}
		data.s++;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buf);
	return (data.chars_written);
}

static int	init_data(t_data *data, const char *format)
{
	data->s = format;
	data->chars_written = 0;
	data->buf = malloc(BUF_SIZE * sizeof(char));
	if (data->buf == NULL)
		return (-1);
	ft_memset(data->buf, 0, BUF_SIZE * sizeof(char));
	data->buffer_index = 0;
	return (0);
}

/*
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
	else if (specifier == 'u')
		count += ft_putunbr_printf(va_arg(ap, unsigned int), 1);
	else if (specifier == 'x')
		count += ft_puthex_printf(va_arg(ap, unsigned int), 1, 'l');
	else if (specifier == 'X')
		count += ft_puthex_printf(va_arg(ap, unsigned int), 1, 'u');
	else if (specifier == '%')
		count += ft_putchar_printf('%', 1);
	return (count);
}
*/
