/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:11:51 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/18 20:45:31 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	num1 = INT_MAX;
	int	num2 = INT_MIN;
	printf("%d\n", num1 + 1);
	printf("%d\n", num2 - 1);

	return (0);
}
