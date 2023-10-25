CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c get_next_line.c get_next_line_utils.c check_map.c check_map_way.c image.c move.c init.c image2.c ft_printf.c ft_printf_util.c check_map_way_util.c
OBJS = $(SRCS:%.c=%.o)
NAME = so_long

all : $(NAME)                                                                                                                               

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	$(CC) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJS)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : re all fclean clean
