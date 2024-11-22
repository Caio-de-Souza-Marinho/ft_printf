/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:05 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/22 02:50:40 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	init_data(t_data *data, const char *format);
static void	render_format(t_data *data);

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
			write_buf(&data, *data.s);
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

// Wrapper for all rendering functions
static void	render_format(t_data *data)
{
	char	specifier;

	specifier = data->format.specifier;
	if (specifier == 'c')
		printf_char(data, va_arg(data->ap, int));
	else if (specifier == 's')
		printf_str(data, va_arg(data->ap, char *));
	/*
	else if (specifier == 'p')
		ft_putptr_printf(va_arg(ap, unsigned long), 1);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr_printf(va_arg(ap, int), 1);
	else if (specifier == 'u')
		ft_putunbr_printf(va_arg(ap, unsigned int), 1);
	else if (specifier == 'x')
		ft_puthex_printf(va_arg(ap, unsigned int), 1, 'l');
	else if (specifier == 'X')
		ft_puthex_printf(va_arg(ap, unsigned int), 1, 'u');
	*/
	else if (specifier == '%')
		printf_char(data, '%');
}
