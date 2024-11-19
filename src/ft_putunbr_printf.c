/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:59:57 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/18 21:11:12 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_printf(unsigned int nbr, int fd)
{
	long	num;
	int		count;

	count = 0;
	num = nbr;
	if (num >= 10)
		count += ft_putunbr_printf(num / 10, fd);
	count += ft_putchar_printf((num % 10) + '0', fd);
	return (count);
}
