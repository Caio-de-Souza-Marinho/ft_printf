/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:33:10 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/18 21:39:41 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_printf(int c, int fd);
int	ft_putstr_printf(char *s, int fd);
int	ft_putptr_printf(unsigned long ptr, int fd);
int	ft_putptr_hex_printf(unsigned long ptr, int fd);
int	ft_putnbr_printf(int nbr, int fd);
int	ft_putunbr_printf(unsigned int nbr, int fd);
int	ft_puthex_printf(unsigned int nbr, int fd, char type);

#endif 
