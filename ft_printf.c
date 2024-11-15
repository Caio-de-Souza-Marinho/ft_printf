/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:13:05 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/15 18:04:28 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	ft_printf(const char *format, ...)
{
	int	count;
	int	i;
	
	i = 0;
	while (format[i] != '\0')
	{
		count = 0;
		i++;
	}
	count = 13;
	return (count);
}
