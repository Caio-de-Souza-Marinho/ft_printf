/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:59:57 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/18 20:24:41 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int nbr, int fd)
{
	long	num;
	int		count;

	count = 0;
	num = nbr;
	if (num < 0)
	{
		count += ft_putchar_printf('-', fd);
		num = -num;
	}
	if (num >= 10)
		count += ft_putnbr_printf(num / 10, fd);
	count += ft_putchar_printf((num % 10) + '0', fd);
	return (count);
}
