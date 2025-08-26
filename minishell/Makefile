NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -I libft -g -O0   # <- Ajouté -g et -O0 pour debug
RM = rm -f

SRC_DIR = src
OBJ_DIR = obj

# Tous les .c du projet
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# --------------------- Règles ---------------------

all: libft $(NAME)

# Compile libft avant tout
libft:
	$(MAKE) -C libft CFLAGS="$(CFLAGS)"

# Génère l'exécutable
$(NAME): $(OBJS) libft
	@mkdir -p $(dir $(OBJS))
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -lreadline -o $(NAME)

# Compile les .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des .o du projet et de libft
clean:
	$(MAKE) -C libft clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
