#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define RED    "\033[1;31m"
# define RST    "\033[0m"

typedef struct s_shell
{
    char **env;
}   t_shell;


// parse.c
void parse_command(char *input, t_shell *shell);

// utils.c
// void    ft_malloc(size_t size);
// pid_t   ft_fork(void);

// free.c
void free_shell(t_shell *shell);


#endif