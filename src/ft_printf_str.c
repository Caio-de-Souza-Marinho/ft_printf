/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:34:51 by caide-so          #+#    #+#             */
/*   Updated: 2025/04/15 10:49:06 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_str_padding(t_data *data, int print_len);
static int	get_print_len(t_data *data, int str_len, int is_null);
static void	handle_null_str(t_data *data, char **s, int *is_null);

void	printf_str(t_data *data, char *s)
{
	int	print_len;
	int	is_null;

	is_null = 0;
	handle_null_str(data, &s, &is_null);
	print_len = get_print_len(data, s_len(s), is_null);
	set_str_padding(data, print_len);
	if (data->format.left_justified)
	{
		if (print_len > 0)
			putstr_buf_n(s, print_len, data);
		putchar_buf_n(' ', data->format.padding_spaces, data);
	}
	else
	{
		putchar_buf_n(' ', data->format.padding_spaces, data);
		if (print_len > 0)
			putstr_buf_n(s, print_len, data);
	}
}

static void	handle_null_str(t_data *data, char **s, int *is_null)
{
	if (*s != NULL)
		return ;
	*s = "(null)";
	*is_null = 1;
	if (data->format.precision_value >= 0 && data->format.precision_value < 5)
		data->format.precision_value = 0;
}

static int	get_print_len(t_data *data, int str_len, int is_null)
{
	int	precision;

	precision = data->format.precision_value;
	if (precision < 0)
		return (str_len);
	if (is_null && precision == 0)
		return (0);
	if (is_null && precision < 5)
		return (0);
	if (precision < str_len)
		return (precision);
	return (str_len);
}

static void	set_str_padding(t_data *data, int print_len)
{
	int	width;

	width = data->format.width_value;
	if (width <= 0)
		return ;
	data->format.padding_spaces = width - print_len;
	if (data->format.padding_spaces < 0)
		data->format.padding_spaces = 0;
}
