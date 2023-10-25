CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_split.c ft_substr.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS2 = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS1 = $(SRCS1:%.c=%.o)
OBJS2 = $(SRCS2:%.c=%.o)
NAME = libft.a

ifdef WITH_BONUS
	OBJS = $(OBJS1) $(OBJS2)
else
	OBJS = $(OBJS1)
endif

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $^

bonus :
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJS1)
	rm -f $(OBJS2)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : re all fclean clean bonus
