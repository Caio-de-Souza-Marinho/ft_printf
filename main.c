/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:11:51 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/24 21:28:26 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	ft_printf("[%-11p %-12p]\n", (void *)INT_MIN, (void *)INT_MAX);
	printf("[%-11p %-12p]\n", (void *)INT_MIN, (void *)INT_MAX);

	ft_printf("[%-13p %-14p]\n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("[%-13p %-14p]\n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
}

/*
TEST(27, print(" %-11p %-12p ", INT_MIN, INT_MAX));
TEST(28, print(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));
*/
