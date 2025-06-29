# Nom de l'exécutable
NAME = push_swap

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Fichiers sources (ajuste selon tes fichiers)
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

# Fichiers objets générés
OBJS = $(SRCS:.c=.o)

# Fichier header
HEADER = push_swap.h

# Règle par défaut : compiler et linker
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compilation des fichiers .c en .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyer les objets + l'exécutable
fclean: clean
	rm -f $(NAME)

# Recompiler tout
re: fclean all

.PHONY: all clean fclean re
