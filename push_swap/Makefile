CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS1 = main.c push_swap.c ps_function_1.c ps_function_2.c ps_function_3.c sort.c calculate.c sort_function.c sort_function_2.c ft_atoi.c ft_split.c main_util.c
SRCS2 = checker.c ps_function_c_1.c ps_function_c_2.c ps_function_c_3.c ft_atoi.c ft_split.c get_next_line.c get_next_line_utils.c error.c init_function.c main_util.c
OBJS1 = $(SRCS1:%.c=%.o)
OBJS2 = $(SRCS2:%.c=%.o)
NAME = push_swap
BONUS_NAME = checker

all : $(NAME)

bonus: $(BONUS_NAME)                                                                                                                                 

.c.o : $(SRCS1)
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS1)
	$(CC) -o $@ $(OBJS1)

$(BONUS_NAME): $(OBJS2)
	$(CC) -o $@ $(OBJS2)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : re all fclean clean
