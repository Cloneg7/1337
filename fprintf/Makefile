C_FILES	=	files/ft_fprintf.c	files/ft_is_flag.c  \
			files/ft_print_c.c	files/ft_print_s.c  \
			files/ft_print_p.c	files/ft_print_x.c  \
			files/ft_print_u.c	files/ft_print_di.c \
			files/ft_print_sp.c	files/ft_print_xx.c \
			files/ft_precision_di.c
O_FILES =	${C_FILES:.c=.o}
H_FILE	=	files/ft_printf.h
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
CC		=	cc

all: ${NAME}

bonus: ${NAME}

files/%.o: files/%.c ${H_FILE}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${O_FILES}
		ar -rcs $@ $^

clean:
	rm -f ${O_FILES}

fclean: clean
		rm -f ${NAME}

re: fclean all
