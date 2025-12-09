/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:41:26 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:19:05 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print une erreur et exit avec le bon code
static void	print_error_and_exit(char *cmd, char *msg, int code, t_pipe *p)
{
	ft_putstr_fd("", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	cleanup_child_resources(p);
	exit(code);
}

// Gère les erreurs pour les commandes avec chemin absolu/relatif.
static void	handle_path_errors(char *cmd, t_pipe *p)
{
	struct stat	st;

	if (access(cmd, F_OK) != 0)
		print_error_and_exit(cmd, "No such file or directory", 127, p);
	if (stat(cmd, &st) == 0 && S_ISDIR(st.st_mode))
		print_error_and_exit(cmd, "Is a directory", 126, p);
	if (access(cmd, X_OK) != 0)
		print_error_and_exit(cmd, "Permission denied", 126, p);
}

// exec une commande externe avec execve
static void	exec_external_cmd(t_cmd *cmd, t_pipe *p, char *path)
{
	char	**filtered_env;

	filtered_env = filter_env_for_exec(p->envp);
	if (!filtered_env)
	{
		cleanup_child_resources(p);
		exit(1);
	}
	execve(path, cmd->argv, filtered_env);
	if (errno == EACCES || errno == EISDIR)
		print_error_and_exit(cmd->argv[0], strerror(errno), 126, p);
	perror("minishell");
	cleanup_child_resources(p);
	exit(127);
}

// exec les cmds de la bonne maniere builtin/execve
static void	exec_cmd(t_cmd *cmd, t_pipe *p)
{
	char	*path;
	int		exit_code;

	if (is_builtin(cmd->argv[0]))
	{
		exit_code = exec_builtin(cmd->argv, p);
		cleanup_child_resources(p);
		exit(exit_code);
	}
	if (ft_strcmp(cmd->argv[0], ".") == 0)
		print_error_and_exit(cmd->argv[0], "filename argument required", 2, p);
	path = find_cmd(cmd->argv[0], p->envp);
	if (!path)
	{
		if (ft_strchr(cmd->argv[0], '/'))
			handle_path_errors(cmd->argv[0], p);
		print_error_and_exit(cmd->argv[0], "command not found", 127, p);
	}
	exec_external_cmd(cmd, p, path);
}

// permet d'exec une commande dans un processus enfant de la bonne manière
// dans le print faire "''" ou ""
void	child_process(t_pipe *p, int i)
{
	t_cmd	*cmd;
	int		in_pipeline;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	cmd = p->cmds_meta[i];
	in_pipeline = (p->n > 1);
	if (!cmd->argv || !cmd->argv[0])
	{
		cleanup_child_resources(p);
		exit(0);
	}
	setup_child(p, i, cmd, in_pipeline);
	expand_vars_new(cmd->argv, p->envp, p->last_exit, p);
	clean_argv(cmd->argv);
	if (!cmd->argv[0] || !cmd->argv[0][0])
	{
		cleanup_child_resources(p);
		exit(0);
	}
	exec_cmd(cmd, p);
}
