/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:39:54 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/18 21:52:07 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_printf(unsigned int nbr, int fd, char type)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex_printf(nbr / 16, fd, type);
	if (type == 'l')
		count += ft_putchar_printf("0123456789abcdef"[nbr % 16], fd);
	else if (type == 'u')
		count += ft_putchar_printf("0123456789ABCDEF"[nbr % 16], fd);
	return (count);
}
