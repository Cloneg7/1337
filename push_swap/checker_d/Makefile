C_FILES	= ft_checker.c ft_get_args.c ft_get_args2.c ft_get_ops.c operations.c
O_FILES	= $(C_FILES:.c=.o)
H_FILE	= ft_checker.h
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
NAME	= checker


all : libft gnl $(NAME) install

%.o: %.c $(H_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	@$(CC) $(CFLAGS) -o $@ $^ ../gnl/gnl.a ../libft/libft.a

gnl:
	@cd ../gnl && make

libft:
	@cd ../libft && make

clean:
	@rm -f $(O_FILES)
	@cd ../gnl && make clean
	@cd ../libft && make clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

install:
	@mv $(NAME) ../$(NAME)