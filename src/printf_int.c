/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:49:10 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/24 19:54:15 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_padding_zeros(t_data *data);
static void	set_padding_zeros_pt_2(t_data *data);
static void	set_padding_spaces(t_data *data);
static void	put_sign(t_data *data);

void	printf_int(t_data *data, t_union_int int_values)
{
	itoa_buf(data, int_values);
	set_padding_zeros(data);
	set_padding_spaces(data);
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

static void	set_padding_zeros(t_data *data)
{
	if (data->format.precision_value >= 0)
	{
		if (data->format.precision_value > data->format.nbr_len)
		{
			data->format.padding_zeros = data->format.precision_value
				- data->format.nbr_len;
			return ;
		}
	}
	if (data->format.zero_pad)
	{
		if (data->format.left_justified)
			return ;
	}
	if (data->format.width_value > data->format.nbr_len)
		data->format.padding_zeros = data->format.width_value
			- data->format.nbr_len;
	set_padding_zeros_pt_2(data);
}

static void	set_padding_zeros_pt_2(t_data *data)
{
	if (data->format.specifier == 'u')
		return ;
	else if ((in("xX", data->format.specifier) && data->format.hash
			&& data->format.buf_temp[0] != '0')
		|| data->format.specifier == 'p')
		data->format.padding_zeros -= 2;
	else if (data->format.is_negative || (!data->format.is_negative
			&& (data->format.plus || data->format.space)))
		data->format.padding_zeros--;
	if (data->format.padding_zeros < 0)
		data->format.padding_zeros = 0;
}

static void	set_padding_spaces(t_data *data)
{
	data->format.padding_spaces = data->format.width_value
		- data->format.padding_zeros - data->format.nbr_len;
	if (in("puxX", data->format.specifier))
	{
		if ((in("xX", data->format.specifier) && data->format.hash
				&& data->format.buf_temp[0] != '0')
			|| data->format.specifier == 'p')
			data->format.padding_zeros -= 2;
		return ;
	}
	if (data->format.is_negative)
	{
		data->format.padding_spaces--;
		return ;
	}
	if (!data->format.is_negative && data->format.plus)
	{
		data->format.padding_spaces--;
		return ;
	}
	if (!data->format.is_negative && data->format.space)
	{
		data->format.padding_spaces--;
		return ;
	}
}

static void	put_sign(t_data *data)
{
	if (data->format.base == 16)
	{
		if ((in("xX", data->format.specifier) && data->format.hash
				&& data->format.buf_temp[0] != '0')
			|| data->format.specifier == 'p')
		{
			if (data->format.upper_case)
				putstr_buf_n("0X", 2, data);
			else
				putstr_buf_n("0x", 2, data);
		}
	}
	else if (data->format.signed_value)
	{
		if (data->format.is_negative)
			putchar_buf_n('-', 1, data);
		else if (!data->format.is_negative)
		{
			if (data->format.plus)
				putchar_buf_n('+', 1, data);
			else if (!data->format.plus && data->format.space)
				putchar_buf_n(' ', 1, data);
		}
	}
}
