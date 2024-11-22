/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:33:10 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/21 21:31:51 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 4096
# define FLAGS "+- 0#"
# define NUMBERS "0123456789"
# define SPECIFIERS "cspdiuxX%"

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
	int		base;
	int		upper_case;
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

int		ft_printf(const char *format, ...);

// utils
void	*ft_memset(void *s, int c, size_t n);
int		in(const char *s, char c);

// parser
int		parse_format(t_data *data);

// buffer
void	write_buf(t_data *data, char c);
void	flush_buf(t_data *data);
void	putchar_buf_n(char c, int n, t_data *data);

// print
void	printf_char(t_data *data, int c);

#endif 
