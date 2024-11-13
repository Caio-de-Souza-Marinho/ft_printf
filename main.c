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

int	sum(int count, ...)
{
	va_list	ap;
	int	i;
	int	s;
	va_start(ap, count);
	i = 0;
	s = 0;
	while (i < count)
	{
		int x = va_arg(ap, int);
		s += x;
		i++;
	}
	va_end(ap);
	return (s);
}

int	main(void)
{
	printf("Sum is %d:\n", sum(1, 2, 3));
	return (0);
}
