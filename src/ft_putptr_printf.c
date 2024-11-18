/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:02:51 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/17 23:45:28 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_printf(unsigned long ptr, int fd)
{
	int	count;

	if (ptr == 0)
		count = ft_putstr_printf("(nil)", fd);
	else
	{
		count = ft_putstr_printf("0x", fd);
		count += ft_putptr_hex_printf(ptr, fd);
	}
	return (count);
}
