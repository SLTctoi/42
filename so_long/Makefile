NAME = so_long
SRCS = main.c map.c img.c key.c player_pos.c
OBJS = $(SRCS:.c=.o)
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
