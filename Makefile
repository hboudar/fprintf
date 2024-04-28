C_FILES	=	ft_printf.c  ft_is_flag.c ft_print_c.c  ft_print_s.c\
			ft_print_p.c  ft_print_x.c ft_print_u.c  ft_print_di.c\
			ft_print_sp.c ft_print_xx.c ft_precision_di.c

O_FILES =	${C_FILES:.c=.o}
H_FILE	=	ft_printf.h
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
CC		=	cc

all bonus: ${NAME}

%.o: %.c ${H_FILE}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${O_FILES}
		ar -rcs $@ $^

clean:
	rm -f ${O_FILES}

fclean: clean
		rm -f ${NAME}

re: fclean all
