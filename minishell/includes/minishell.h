#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define RST "\033[0m"

typedef struct s_shell
{
	char	**env;
	char	**var;
	char	*path;
}			t_shell;

// parse.c
void		parse_command(char *input, t_shell *shell);

// pid_t   ft_fork(void);

// free.c
void		free_shell(t_shell *shell);

#endif