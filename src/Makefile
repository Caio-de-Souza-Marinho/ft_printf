NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

SRCS		= ft_printf.c \
		  ft_putchar_printf.c \
		  ft_putstr_printf.c \
		  ft_putptr_printf.c \
		  ft_putptr_hex_printf.c \
		  ft_putnbr_printf.c \
		  ft_putunbr_printf.c \
		  ft_puthex_printf.c

OBJS		= ${SRCS:.c=.o}

all:		${NAME}

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
