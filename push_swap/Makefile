NAME		= push_swap
C_FILES		= push_swap.c push_swap_utils1.c push_swap_utils2.c operations.c sort_stack_utils1.c sort_stack_utils2.c
O_FILES		= $(C_FILES:.c=.o)
H_FILE		= push_swap.h
CFLAGS		= -Wall -Wextra -Werror
CC			= cc

all: prf $(NAME)

%.o: %.c $(H_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	@$(CC) $(CFLAGS) -o $@ $^ ft_printf/libftprintf.a

prf:
	@cd ft_printf && make

bonus:
	@cd checker_d && make

clean:
	@rm -f $(O_FILES)
	@cd ft_printf && make clean
	@cd gnl && make clean
	@cd libft && make clean
	@cd checker_d && make clean

fclean: clean
	@rm -f $(NAME) checker
	@cd ft_printf && make fclean
	@cd gnl && make fclean
	@cd libft && make fclean

re: fclean all

