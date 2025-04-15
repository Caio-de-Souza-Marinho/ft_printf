/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:12:23 by caide-so          #+#    #+#             */
/*   Updated: 2025/04/15 13:22:04 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Fills memory with a specified byte value
// 1. Casts s to an unsigned char pointer
// 2. Writes c to the first n bytes of s
//
// Note: Used to initialize buffers and structs
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*typed_s;
	size_t			i;

	i = 0;
	typed_s = (unsigned char *)s;
	while (i < n)
	{
		typed_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// Checks if a character exists in a string
// 1. Iterates through s to find c
int	in(const char *s, char c)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

// Computes the length of a string
// 1. Counts characters until null terminator
// 2. Returns 0 for NULL input
int	s_len(const char *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
