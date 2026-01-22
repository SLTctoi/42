NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./libft -I./minilibx-linux

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = srcs
PARSING_DIR = $(SRC_DIR)/parsing
UTILS_DIR = $(SRC_DIR)/utils
VALIDATION_DIR = $(SRC_DIR)/validation
PLAYER_DIR = $(SRC_DIR)/player
GAME_DIR = $(SRC_DIR)/game

SRCS = $(SRC_DIR)/main.c \
       $(UTILS_DIR)/free.c \
       $(UTILS_DIR)/error.c \
       $(PARSING_DIR)/parsing_map.c \
       $(PARSING_DIR)/parsing_line.c \
       $(PARSING_DIR)/parsing_assign.c \
       $(PARSING_DIR)/parsing_color.c \
       $(PARSING_DIR)/parsing_extract.c \
       $(PARSING_DIR)/parsing_realloc.c \
       $(PARSING_DIR)/parsing_utils.c \
       $(PARSING_DIR)/get_next_line.c \
       $(VALIDATION_DIR)/check_entry.c \
       $(VALIDATION_DIR)/validate_map_closed.c \
       $(VALIDATION_DIR)/validate_map_spaces.c \
       $(VALIDATION_DIR)/validate_player.c \
       $(VALIDATION_DIR)/validate_elements.c \
       $(PLAYER_DIR)/position.c \
       $(PLAYER_DIR)/move.c \
       $(GAME_DIR)/init.c \
       $(GAME_DIR)/render_drawmap.c \
       $(GAME_DIR)/render_drawpixel.c \
       $(GAME_DIR)/render_drawplayer.c \
       $(GAME_DIR)/render_drawsquare.c \
       $(GAME_DIR)/raycasting.c \
       $(GAME_DIR)/raycasting_init.c \
       $(GAME_DIR)/raycasting_dda.c \
       $(GAME_DIR)/raycasting_render.c \
       $(GAME_DIR)/texture_loader.c \
       $(GAME_DIR)/texture_utils.c \

       

OBJS = $(SRCS:.c=.o)

# -------------------------- Rules -------------------------- #

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=definite,indirect,possible \
		--track-origins=yes --suppressions=valgrind.supp ./$(NAME) map/test.cub

.PHONY: all clean fclean re valgrind

.PHONY: all clean fclean re