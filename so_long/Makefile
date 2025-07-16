# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 14:09:56 by mchrispe          #+#    #+#              #
#    Updated: 2025/07/16 10:26:59 by mchrispe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/main.c src/map.c src/img.c src/key.c src/pos.c \
       src/free.c src/parse_entry.c src/utils.c src/valid_path.c \
       libft/get_next_line/get_next_line.c \
       libft/get_next_line/get_next_line_utils.c src/valid_map.c \
	   src/valid_path2.c libft/get_next_line/get_next_line_utils_2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -Ilibft

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

PRINTF_DIR = libft/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -L$(PRINTF_DIR) -lftprintf


all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(PRINTF_LIB) $(LDFLAGS) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
