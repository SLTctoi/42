/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:05:53 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:38:24 by mchrispe         ###   ########.fr       */
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
	int				heredoc_fd;
	int				append;
	int				infile_error;
}					t_cmd;

typedef struct s_pipe
{
	t_cmd			**cmds_meta;
	char			***cmds;
	int				**fd;
	pid_t			*pids;
	int				n;
	int				nb_cmds;
	char			**envp;
	int				size_envp;
	int				last_exit;
	int				var_not_found;
}					t_pipe;

typedef struct s_params
{
	int				i;
	int				nb_cmds;
	t_pipe			*p;
}					t_params;

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
	int				has_unquoted_var;
}					t_quote_state;

typedef struct s_exp_params
{
	int				last_exit;
	t_pipe			*p;
}					t_exp_params;

typedef struct s_heredoc_ctx
{
	t_pipe			*p;
	char			*clean_lim;
	int				should_expand;
}					t_heredoc_ctx;

/* ----------------------------- Main --------------------------------- */
void				execute_pipeline(t_cmd **cmds_meta, int n, char **envp,
						t_pipe *p);

t_cmd				**init_cmds(char ***cmds, int nb_cmds, t_pipe *p);
int					init_minishell(t_pipe *p, char **envp);
int					handle_input(t_pipe *p);
void				init_signals(void);

void				child_process(t_pipe *p, int i);
int					**init_pipes(int n);
void				close_all_pipes(int **fd, int n);
void				free_all_fd(int **fd, int n);
void				init_pipeline_ctx(t_pipe *p, int **fd, int n, char **envp);

/* ---------------------------- Parsing ------------------------------- */
char				***parse_commands(char *input, int *nb_cmds, t_pipe *p);

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
int					handle_heredoc_attached(char ***cmds, t_cmd *cmd, int *j,
						t_params prm);
int					check_heredoc_syntax(char *token, t_params prm);
void				update_heredoc_attached(t_cmd *cmd, int fd,
						char *delimiter);
int					check_pipe_end(char *input, t_pipe *p);

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

/* -------------------------- Redirection ----------------------------- */
void				handle_redirs(t_cmd *cmd, int in_pipeline);
int					here_doc(char *limiter, t_pipe *p);
void				handle_heredoc_sigint(int sig);

int					has_quotes(const char *s);
char				*expand_heredoc_line(char *line, t_pipe *p);
void				setup_child(t_pipe *p, int i, t_cmd *cmd, int in_pipeline);

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
void				wait_and_store_exit(t_pipe *p, pid_t *pids, int n);

/* --------------------------- Builtins / Env --------------------------- */
int					is_builtin(char *cmd);
int					exec_builtin(char **args, t_pipe *p);
int					is_valid_var(char *name);
int					builtin_echo(char **args, t_pipe *p);
int					builtin_cd(char **args, t_pipe *p);
int					cd_minus(t_pipe *p);
char				*get_cd_path(char **args, t_pipe *p);
int					change_directory(t_pipe *p, char *path);
int					builtin_pwd(t_pipe *p, char **args);
int					builtin_env(char **args, t_pipe *p);
int					builtin_exit(char **args, t_pipe *p);
int					builtin_export(char **args, t_pipe *p);
int					builtin_unset(char **args, t_pipe *p);
char				*strip_all_quotes(const char *s);

char				**copy_env(char **envp);
void				remove_env(char ***envp, char *key);
void				update_var_env(char ***envp, char *key, char *value);
char				**sorted_env(char **env);
int					size_env(char **env);
int					index_env(char **envp, char *key);
char				**filter_env_for_exec(char **envp);

/* ---------------------------- Expansion ------------------------------- */
void				expand_vars_new(char **argv, char **envp, int last_exit,
						t_pipe *p);
char				*parse_and_expand(const char *s, char **envp, int last_exit,
						t_pipe *p);
char				*get_val_env(const char *var, char **envp, t_pipe *p);
void				append_str(char **res, const char *str);
void				append_char(char **res, char c);
void				expand_variable(const char *s, t_quote_state *st,
						t_pipe *p);
void				handle_backslash(const char *s, t_quote_state *st);

int					count_words_ws(const char *s);
char				**split_on_whitespace(const char *s);
int					count_split_args(char **split);
int					copy_split_to_argv(char **new_argv, char **split, int k);
int					has_unquoted_variable(const char *s);

int					count_total_args(char **argv, char **envp, int last_exit,
						t_pipe *p);
void				fill_new_argv(char **new_argv, char **argv, char **envp,
						t_exp_params prm);
char				**rebuild_argv_with_splitting(char **argv, char **envp,
						int last_exit, t_pipe *p);

/* ---------------------------- Utilities ------------------------------- */
char				*find_cmd(char *cmd, char **envp);

void				free_triple_pointer(char ***ptr);
void				free_cmd(t_cmd *cmd);
void				free_split(char **split);
void				cleanup_minishell_resources(t_pipe *p);
void				cleanup_child_resources(t_pipe *p);

char				*strip_wrapping_quotes(const char *s);
char				*remove_quotes(char *str);
char				*extract_quoted_content(char *str);

char				*ft_get_next_word(const char **s, const char *delims);
char				**ft_split_quote(const char *s, const char *delims);
int					ft_is_delim(char ch, const char *delims);
int					ft_word_count(const char *s, const char *delims);
char				*ft_strndup(const char *s, int len);
void				ft_free_all(char **arr, int i);
const char			*ft_advance_delim(const char *s, const char *delims);
char				**split_redirections(const char *token);
char				**expand_redirect_tokens(char **tokens);

#endif