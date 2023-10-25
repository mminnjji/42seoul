CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_util.c
OBJS = $(SRCS:%.c=%.o) 

NAME = libftprintf.a

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : re all fclean clean bonus
