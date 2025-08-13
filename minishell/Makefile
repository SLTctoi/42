NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -Ilibft
READLINE = -lreadline

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/parse.c \
	  $(SRC_DIR)/utils.c \
	  $(SRC_DIR)/free.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(READLINE) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re