NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -fPIE
RM	= rm -f

SRCS		= ft_printf.c \
		  ft_printf_utils.c \
		  ft_printf_parser.c \
		  ft_printf_buffer.c \
		  ft_printf_char.c \
		  ft_printf_str.c \
		  ft_printf_int.c \
		  ft_printf_int_utils.c \

OBJS		= ${SRCS:.c=.o}

BONUS		= ft_printf_bonus.c \
		  ft_printf_utils_bonus.c \
		  ft_printf_parser_bonus.c \
		  ft_printf_buffer_bonus.c \
		  ft_printf_char_bonus.c \
		  ft_printf_str_bonus.c \
		  ft_printf_int_bonus.c \
		  ft_printf_int_utils_bonus.c \

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
