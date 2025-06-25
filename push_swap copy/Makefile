# Nom de l'exécutable
NAME = push_swap

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Fichiers sources (ajuste selon tes fichiers)
SRCS = parsing.c \
       main.c \
       index.c \
       free.c \
       rules/push.c \
	   rules/rotate.c \
	   rules/rrotate.c \
	   rules/swap.c \
	   list/list.c \
	   libft/ft_atoi.c \
	   libft/ft_lstadd_back_bonus.c \
	   libft/ft_split.c
	   

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
