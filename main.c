/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:11:51 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/12 21:17:57 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

float	average(int count, ...)
{
	va_list	ap;
	int	total;
	int	i;

	va_start(ap, count);
	total = 0;
	i = 0;
	while (i < count)
	{
		total += va_arg(ap, int);
		i++;
	}
	return (float)total / count;
}

int	sum(int count, ...)
{
	va_list	ap;
	int	i;
	int	sum;
	int	arg;

	i = 0;
	sum = 0;
	va_start(ap, count);
	while (i < count)
	{
		arg = va_arg(ap, int);
		sum += arg;
		i++;
	}
	va_end(ap);
	return (sum);
}

int	main(void)
{
	printf("Sum is: %d\n", sum(2, 5, 5));
	printf("Average is: %f\n", average(2, 5, 5));
	return (0);
}
