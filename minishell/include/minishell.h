#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RED "\033[1;31m"
# define RST "\033[0m"

typedef struct s_shell
{
	char	**env;
	char	**var;
	char	*path;
}			t_shell;

typedef struct s_minishell
{
	int	in;
	int out;
}			t_minishell;

typedef struct s_pipe
{
	int pipe_in;
	int pipe_out;
}			t_pipe;
// free.c
void		free_shell(t_shell *shell);
void free_string_array(char **arr);
void free_exit(int i);

// init.c 
int init_path(t_shell *env);

// main.c

// parse.c
void		parse_command(char *input, t_shell *shell);

// update.c
int update_path(t_shell *env);

// utils_2.c
char **copy_str_array_without_last(char **lst);

// utils.c
void    ft_write_error(const char *err);
void    sort_lst(char **lst);
char **copy_string_array(char **lst);
int ft_strarray_len(char **lst);

// split_quote
// split_quote_2.c
char	*ft_get_next_word(const char **s, const char *delims);
char	**ft_split_quote(const char *s, const char *delims);

// split_quote.c
int	ft_is_delim(char ch, const char *delims);
int	ft_word_count(const char *s, const char *delims);
char	*ft_strndup(const char *s, int len);
void	ft_free_all(char **arr, int i);
const char	*ft_advance_delim(const char *s, const char *delims);

// builtins
// cd.c
int cd(const char *path, t_shell *env);

// echo.c
void echo(char *str);

// env.c
void env(t_shell *shell);

// export_2.c
int	var_name_cmp(char *s1, char *s2);
int	is_in_str_array(char **array, char *str);
char	**add_to_str_array(char **array, char *str);
void	replace_or_add(char ***env, char *str);

// export.c
int export(char *str, t_shell *shell);
void export_no_arg_no_opt(t_shell *shell);
void export_arg(t_shell *shell, char **args);
int is_valid_identifier(char *s);
void add_or_update_env(t_shell *shell, char *str);

// pwd.c
// void pwd(t_shell *env)

// redirection
// redirection.c
int redirection_loop(char **input);
int	redirection_stdin(char *input ,char *file);
int double_redirection_stdin(char *input, const char *delim);
int redirection_stdout(char *input, char *file);

#endif