/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hex_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:01:19 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/17 23:45:07 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hex_printf(unsigned long ptr, int fd)
{
	int	count;

	count = 0;
	if (ptr >= 16)
		count += ft_putptr_hex_printf(ptr / 16, fd);
	count += ft_putchar_printf("0123456789abcdef"[ptr % 16], fd);
	return (count);
}
