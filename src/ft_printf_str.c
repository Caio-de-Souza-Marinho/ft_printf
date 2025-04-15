/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:34:51 by caide-so          #+#    #+#             */
/*   Updated: 2025/04/14 22:57:43 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_str_padding_spaces(t_data *data, char *s, int is_null);
static int	get_print_len(t_data *data, int str_len);

// [-][width][.precision]
void	printf_str(t_data *data, char *s)
{
	int		str_len;
	int		print_len;
	int		is_null;
	char	*null_str;

	is_null = 0;
	null_str = "(null)";
	if (s == NULL)
	{
		s = null_str;
		is_null = 1;
	}
	str_len = s_len(s);
	print_len = get_print_len(data, str_len);
	set_str_padding_spaces(data, s, is_null);
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

static int	get_print_len(t_data *data, int str_len)
{
	if (data->format.precision_value >= 0)
	{
		if (data->format.precision_value < str_len)
			return (data->format.precision_value);
	}
	return (str_len);
}

static void	set_str_padding_spaces(t_data *data, char *s, int is_null)
{
	int	len;
	int	print_len;

	len = s_len(s);
	print_len = get_print_len(data, len);
	if (is_null) {
		if (data->format.precision_value >= 0) {
			if (data->format.precision_value == 0) {
				print_len = 0;
			} else if (data->format.precision_value < 5) {
				print_len = 0;
			} else {
				print_len = data->format.precision_value;
			}
		}
	}
	if (data->format.width_value > 0) {
		data->format.padding_spaces = data->format.width_value - print_len;
		if (data->format.padding_spaces < 0)
			data->format.padding_spaces = 0;
	}
}
