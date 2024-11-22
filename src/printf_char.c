/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:13:02 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/21 21:18:29 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// [-][width]
void	printf_char(t_data *data, int c)
{
	int	width;

	width = data->format.width_value;
	if (width > 1)
	{
		if (data->format.left_justified)
		{
			putchar_buf_n((char)c, 1, data);
			putchar_buf_n(' ', width - 1, data);
		}
		else
		{
			putchar_buf_n(' ', width - 1, data);
			putchar_buf_n((char)c, 1, data);
		}
	}
	else
		putchar_buf_n((char)c, 1, data);
}
