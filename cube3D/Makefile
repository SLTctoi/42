# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 00:00:00 by mchrispe          #+#    #+#              #
#    Updated: 2025/12/30 21:26:43 by mchrispe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./srcs/libft

LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = srcs
PARSING_DIR = $(SRC_DIR)/parsing
UTILS_DIR = $(SRC_DIR)/utils

SRCS = main.c \
	   $(UTILS_DIR)/free.c \
	   $(UTILS_DIR)/error.c \
	   $(PARSING_DIR)/parsing_map.c \
	   $(PARSING_DIR)/parsing_line.c \
	   $(PARSING_DIR)/parsing_assign.c \
	   $(PARSING_DIR)/parsing_color.c \
	   $(PARSING_DIR)/parsing_extract.c \
	   $(PARSING_DIR)/parsing_realloc.c \
	   $(PARSING_DIR)/parsing_utils.c \
	   $(PARSING_DIR)/get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test
