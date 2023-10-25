CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME	= pipex

SRCS 	= srcs/main.c srcs/util.c
OBJS 	= $(SRCS:.c=.o)
MAIN	= srcs/main.c

HEADER	= include


.c.o :	$(SRCS)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
		@make re -C ./libft
		@$(CC) $(OBJS) -Llibft -lft -o $(NAME) -g -fsanitize=address

clean:
					@make clean -C ./libft
					@rm -f $(OBJS)

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re
