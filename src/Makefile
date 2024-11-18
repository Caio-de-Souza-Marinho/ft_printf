NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

SRCS		= ft_printf.c \
		  ft_putchar_printf.c \
		  ft_putstr_printf.c \
		  ft_putptr_printf.c \
		  ft_putptr_hex_printf.c

OBJS		= ${SRCS:.c=.o}
BONUS 		= 
BONUS_OBJS 	= ${BONUS:.c=.o}

all:		${NAME}

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

bonus:		${BONUS_OBJS}
			ar rcs ${NAME} ${BONUS_OBJS}

clean:		
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all bonus clean fclean re
