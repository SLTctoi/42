NAME = so_long

SRCS = main.c map.c img.c key.c pos.c  \
	   free.c parse_entry.c libft/get_next_line/get_next_line.c \
	   libft/get_next_line/get_next_line_utils.c exit.c utils.c \
	   valid_path.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)

PRINTF_DIR = libft/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror $(MLX_INC)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

minilibx:
	$(MAKE) -C $(MLX_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

all: minilibx $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
