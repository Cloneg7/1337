C_FILES	= get_next_line.c get_next_line_utils.c
O_FILES	= $(C_FILES:.c=.o)
H_FILE	= get_next_line.h
CFLAGS	= -Wall -Wextra -Werror
NAME	= gnl.a
CC		= cc

all : ${NAME}

%.o: %.c $(H_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${O_FILES}
	@ar -rcs $@ $^

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
