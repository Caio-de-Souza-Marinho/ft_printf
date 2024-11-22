/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:15:29 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/21 20:44:15 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function is called when
// 1 - the loop is over (format string is over)
// 2 - when buf is full [4k chars]

void	flush_buf(t_data *data)
{
	data->chars_written += write(1, data->buf, data->buffer_index);
	ft_memset(data->buf, 0, BUF_SIZE);
	data->buffer_index = 0;
}

void	write_buf(t_data *data, char c)
{
	if (data->buffer_index == BUF_SIZE)
		flush_buf(data);
	data->buf[data->buffer_index++] = c;
}

void	putchar_buf_n(char c, int n, t_data *data)
{
	if (n <= 0)
		return ;
	while (n--)
		write_buf(data, c);
}
