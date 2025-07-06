NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = 	src/main.c \
		src/utils.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_strnstr.c \
		libft/ft_strncmp.c

OBJS = $(SRCS:.c=.o)

HEADER = pipex.h

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