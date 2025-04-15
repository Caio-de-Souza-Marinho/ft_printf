/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:54:28 by caide-so          #+#    #+#             */
/*   Updated: 2025/04/15 10:53:28 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_nil_pointer(t_data *data)
{
	int	width;

	width = data->format.width_value;
	if (data->format.precision_value == 0)
	{
		print_nil_ptr(data, width);
		return (1);
	}
	else if (data->format.precision_value < 0)
	{
		printf_str(data, "(nil)");
		return (1);
	}
	return (0);
}

void	print_nil_ptr(t_data *data, int width)
{
	char	*nil_str;
	int		nil_len;

	nil_str = "(nil)";
	nil_len = 5;
	if (data->format.left_justified)
	{
		putstr_buf_n(nil_str, nil_len, data);
		if (width > nil_len)
			putchar_buf_n(' ', width - nil_len, data);
	}
	else
	{
		if (width > nil_len)
			putchar_buf_n(' ', width - nil_len, data);
		putstr_buf_n(nil_str, nil_len, data);
	}
}

void	print_formatted_number(t_data *data)
{
	if (data->format.left_justified)
	{
		put_sign(data);
		putchar_buf_n('0', data->format.padding_zeros, data);
		putstr_buf_n(data->format.buf_temp, data->format.nbr_len, data);
		putchar_buf_n(' ', data->format.padding_spaces, data);
	}
	else
	{
		putchar_buf_n(' ', data->format.padding_spaces, data);
		put_sign(data);
		putchar_buf_n('0', data->format.padding_zeros, data);
		putstr_buf_n(data->format.buf_temp, data->format.nbr_len, data);
	}
}
