C_FILES = push_swap.c push_swap_utils1.c push_swap_utils2.c op.c sort_stack_utils1.c sort_stack_utils2.c
O_FILES = $(C_FILES:.c=.o)
H_FILE = push_swap.h
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CC = cc

all: plx $(NAME)

%.o: %.c $(H_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	@$(CC) $(CFLAGS) -o $@ $^ ft_printf/libftprintf.a
	@echo "DONE"

plx:
	@cd ft_printf && make

clean:
	@rm -f $(O_FILES)
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME)
	@cd ft_printf && make fclean

re: fclean all
