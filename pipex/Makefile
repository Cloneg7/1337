CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc

NAME		=	pipex
SRC			=	pipex.c utils.c child.c
OBJS		=	${SRC:.c=.o}

NAME_BONUS	=	pipex_bonus
SRC_BONUS	=	pipex_bonus.c utils_bonus.c child_bonus.c here_doc_bonus.c
OBJS_BONUS	=	${SRC_BONUS:_bonus.c=_bonus.o}

all:  libft.a $(NAME)

bonus: libft.a $(NAME_BONUS)

libft.a:
	@cd libft && make

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^ libft/libft.a

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $^ libft/libft.a gnl/get_next_line.c gnl/get_next_line_utils.c

%_bonus.o: %_bonus.c pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	@cd libft && make clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@cd libft && make fclean

re: fclean all
