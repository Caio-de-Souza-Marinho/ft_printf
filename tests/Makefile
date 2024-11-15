NAME		= libftprintf.a
CC		= cc
RM		= rm -f
TESTFILE	= tests_ft_printf.c
TESTPROGRAM	= printf.tests
SRCDIR		= ../src/

SRCS		= ${SRCDIR}ft_printf.c ${SRCDIR}ft_putchar_printf.c
OBJS		= ${SRCS:.c=.o}

test:		fclean
			make -C ../src
			@${CC} -o ${TESTPROGRAM} -I . -I ${SRCDIR} ${TESTFILE} -L${SRCDIR} -lftprintf
			@./${TESTPROGRAM}

leakfull:
			valgrind --track-origins=yes --error-exitcode=42 --leak-check=full ./${TESTPROGRAM}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} ${TESTPROGRAM}

re:		fclean test

.PHONY:		test leakfull clean fclean re

