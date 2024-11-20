/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:33:10 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/20 18:50:50 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 4096

int		ft_printf(const char *format, ...);
int		ft_putchar_printf(int c, int fd);
int		ft_putstr_printf(char *s, int fd);
int		ft_putptr_printf(unsigned long ptr, int fd);
int		ft_putptr_hex_printf(unsigned long ptr, int fd);
int		ft_putnbr_printf(int nbr, int fd);
int		ft_putunbr_printf(unsigned int nbr, int fd);
int		ft_puthex_printf(unsigned int nbr, int fd, char type);

typedef struct s_format
{
	int		plus;
	int		left_justified;
	int		space;
	int		zero_pad;
	int		hash;
	char	specifier;
	int		width_value;
	int		precision_value;
}	t_format;

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	char		*buf;
	int			buffer_index;
	t_format	format;
}	t_data;

// PROTOTYPES

// utils
void	*ft_memset(void *s, int c, size_t n);

#endif 
