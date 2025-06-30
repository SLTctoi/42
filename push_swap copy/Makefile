NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = src/parsing.c \
       src/main.c \
       src/index.c \
       src/free.c \
       src/rules/push.c \
	   src/rules/rotate.c \
	   src/rules/rrotate.c \
	   src/rules/swap.c \
	   src/list.c \
	   src/libft/ft_atoi.c \
	   src/libft/ft_lstadd_back_bonus.c \
	   src/libft/ft_split.c \
	   src/error.c \
	   src/libft/ft_isdigit.c \
	   src/libft/ft_strlen.c \
	   src/index_2.c \
	   src/algo_force.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
