# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 15:03:04 by mchrispe          #+#    #+#              #
#    Updated: 2025/11/24 11:39:02 by mchrispe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I libft -g -O0
RM = rm -f

SRCS = src/main/main.c \
	src/main/main_init.c \
	src/main/main_loop.c \
	src/main/signal.c \
	src/parsing/parse.c \
	src/parsing/parse_init.c \
	src/parsing/parse_main.c \
	src/parsing/parse_outfile.c \
	src/parsing/parse_tokens.c \
	src/parsing/parse_utils.c \
	src/expansion/dollar_question.c \
	src/expansion/quote_expansion.c \
	src/expansion/quote_expansion_utils.c \
	src/builtins/builtin.c \
	src/builtins/builtin_cd.c \
	src/builtins/builtin_dollar_question.c \
	src/builtins/builtin_echo.c \
	src/builtins/builtin_env.c \
	src/builtins/builtin_exit.c \
	src/builtins/builtin_export.c \
	src/builtins/builtin_pwd.c \
	src/builtins/builtin_unset.c \
	src/builtins/utils_builtin.c \
	src/builtins/env/env_utils.c \
	src/builtins/env/env_utils_2.c \
	src/builtins/env/env_utils_3.c \
	src/redirection/child.c \
	src/redirection/heredoc.c \
	src/redirection/pipe.c \
	src/redirection/pipe_utils.c \
	src/redirection/redir_check.c \
	src/redirection/redir_check_1.c \
	src/redirection/redir_infile.c \
	src/redirection/redir_outfile.c \
	src/redirection/redir_utils.c \
	src/redirection/redir_validation.c \
	src/redirection/redirections.c \
	src/split_quote/split_quote.c \
	src/split_quote/split_quote_2.c \
	src/utils/free.c \
	src/utils/path.c \
	src/utils/quotes.c \
	src/utils/quotes_utils.c

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) -C libft CFLAGS="$(CFLAGS)"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
