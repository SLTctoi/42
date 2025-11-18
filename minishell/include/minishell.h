/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:05:53 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:43:49 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

extern int			g_signal;

typedef struct s_cmd
{
	char			**argv;
	char			*infile;
	char			*outfile;
	char			*heredoc;
	int				append;
}					t_cmd;

typedef struct s_pipe
{
	t_cmd			**cmds_meta;
	int				**fd;
	int				n;
	char			**envp;
	int				size_envp;
	int				last_exit;
}					t_pipe;

typedef struct s_params
{
	int				i;
	int				nb_cmds;
	t_pipe			*p;
}					t_params;

// pour stocker des vars car plus de place a cause des normes
typedef struct s_out_params
{
	t_params		prm;
	int				*redir_error;
	int				append;
}					t_out_params;

typedef struct s_process_params
{
	t_params		p;
	t_out_params	out;
	int				*arg_idx;
}					t_process_params;

typedef struct s_parse_ctx
{
	char			result[4096];
	char			varname[256];
	int				last_exit;
}					t_parse_ctx;

typedef struct s_quote_state
{
	int				in_single;
	int				in_double;
	int				i;
	int				j;
	char			*result;
	char			**envp;
	int				last_exit;
}					t_quote_state;

/* ----------------------------- Main API ------------------------------- */
void				execute_pipeline(t_cmd **cmds_meta, int n, char **envp,
						t_pipe *p);

/* main (core) */
t_cmd				**init_cmds(char ***cmds, int nb_cmds, t_pipe *p);
int					init_minishell(t_pipe *p, char **envp);
int					handle_input(t_pipe *p);
void				init_signals(void);

/* process / child */
void				child_process(t_pipe *p, int i);
int					**init_pipes(int n);
void				close_all_pipes(int **fd, int n);
void				free_all_fd(int **fd, int n);
void				init_pipeline_ctx(t_pipe *p, int **fd, int n, char **envp);

/* ---------------------------- Parsing API ----------------------------- */
char				***parse_commands(char *input, int *nb_cmds, t_pipe *p);

/* parsing helpers */
t_cmd				*init_cmd_struct(void);
void				init_argv(char **argv, int argc);
void				init_process_params(t_process_params *pprm, t_params prm,
						int *redir_error, int *arg_idx);
int					count_args(char ***cmds, int i);
int					set_outfile(t_cmd *cmd, char *token);
int					outfile_error(int nb_cmds, int *redir_error);
int					attached_outfile(char ***cmds, t_cmd *cmd, int *j,
						t_out_params prm);
void				error_syntax_pipe(t_params prm);

/* token handling */
int					check_pipe_after_redir(char ***cmds, int i, int j,
						t_pipe *p);
int					handle_infile_redir(char ***cmds, t_cmd *cmd, int *j,
						t_params prm);
int					handle_heredoc_redir(char ***cmds, t_cmd *cmd, int *j,
						t_params prm);
int					outfile_redir(char ***cmds, t_cmd *cmd, int *j,
						t_out_params prm);
int					add_arg_to_argv(char ***argv_ptr, int *arg_idx, char *arg);
int					process_single_redir(char ***cmds, t_cmd *cmd, int *j,
						t_process_params *prm);
int					process_all_redir(char ***cmds, t_cmd *cmd,
						t_process_params *prm);
t_cmd				*create_single_cmd(char ***cmds, int i, int *redir_error,
						t_params prm);

/* -------------------------- Redirection API --------------------------- */
void				handle_redirs(t_cmd *cmd, int in_pipeline);
int					here_doc(char *limiter);

int					check_file_exists(char *file, t_pipe *p, int nb_cmds);
int					check_file_readable(char *file, t_pipe *p, int nb_cmds);
int					validate_infile(char *infile, t_pipe *p, int nb_cmds);
int					try_create_file(char *unquoted_file, int append);
int					check_infile_access(const char *filename);

char				*get_clean_filename(char *filename);
int					process_infile_simple(t_cmd *cmd, char *filename,
						int nb_cmds, t_pipe *p);
int					handle_infile_redirect(char ***cmds, t_cmd *cmd, int *j_ptr,
						t_params prm);
void				clean_argv(char **argv);

int					handle_prev_outfile(t_cmd *cmd, int nb_cmds, t_pipe *p,
						int *redir_error);
int					create_outfile(char *outfile, int append, t_pipe *p,
						int nb_cmds);
int					handle_outfile_redirect(char ***cmds, t_cmd *cmd,
						int *j_ptr, t_out_params prm);

char				*build_concat_filename(char ***cmds, int i, int *j_ptr);
int					check_quoted_parts(char ***cmds, int i, int j);
int					skip_to_next_token(char ***cmds, int i, int j);

/* --------------------------- Builtins / Env --------------------------- */
int					is_builtin(char *cmd);
int					exec_builtin(char **args, t_pipe *p);
int					is_valid_var(char *name);
int					builtin_echo(char **args, t_pipe *p);
int					builtin_cd(char **args, t_pipe *p);
int					builtin_pwd(t_pipe *p, char **args);
int					builtin_env(char **args, t_pipe *p);
int					builtin_exit(char **args, t_pipe *p);
int					builtin_export(char **args, t_pipe *p);
int					builtin_unset(char **args, t_pipe *p);
int					builtin_dollar_question(t_pipe *p);

char				**copy_env(char **envp);
void				remove_env(char ***envp, char *key);
void				update_var_env(char ***envp, char *key, char *value);
char				**sorted_env(char **env);
int					size_env(char **env);
int					index_env(char **envp, char *key);

/* ---------------------------- Expansion ------------------------------- */
void				expand_vars(char **argv, char **envp, int last_exit);
void				expand_vars_new(char **argv, char **envp, int last_exit);
char				*parse_and_expand(const char *s, char **envp,
						int last_exit);
void				replace_dollar_question(char **argv, t_pipe *p);
char				*get_val_env(const char *var, char **envp);
void				append_str(char **res, const char *str);
void				append_char(char **res, char c);
void				expand_variable(const char *s, t_quote_state *st);
void				handle_backslash(const char *s, t_quote_state *st);

/* ---------------------------- Utilities ------------------------------- */
char				*find_cmd(char *cmd, char **envp);

void				free_triple_pointer(char ***ptr);
void				free_cmd(t_cmd *cmd);
void				free_split(char **split);

char				*strip_wrapping_quotes(const char *s);
char				*remove_quotes(char *str);
char				*extract_quoted_content(char *str);

/* split_quote helpers (local utils) */
char				*ft_get_next_word(const char **s, const char *delims);
char				**ft_split_quote(const char *s, const char *delims);
int					ft_is_delim(char ch, const char *delims);
int					ft_word_count(const char *s, const char *delims);
char				*ft_strndup(const char *s, int len);
void				ft_free_all(char **arr, int i);
const char			*ft_advance_delim(const char *s, const char *delims);

#endif /* MINISHELL_H */