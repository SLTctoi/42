/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:45:21 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/19 14:03:33 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// attend la fin de tous les processus enfant et stock leur sortie
void	wait_and_store_exit(t_pipe *p, pid_t *pids, int n)
{
	int	status;
	int	i;
	int	last_exit_code;

	i = -1;
	last_exit_code = 0;
	while (++i < n)
	{
		if (pids[i] > 0)
		{
			waitpid(pids[i], &status, 0);
			if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == SIGINT)
					write(1, "\n", 1);
				else if (WTERMSIG(status) == SIGQUIT)
					write(1, "Quit (core dumped)\n", 19);
				last_exit_code = 128 + WTERMSIG(status);
			}
			else if (WIFEXITED(status))
				last_exit_code = WEXITSTATUS(status);
		}
	}
	p->last_exit = last_exit_code;
}

static int	should_exec_in_parent(t_cmd *cmd)
{
	if (!is_builtin(cmd->argv[0]))
		return (0);
	if (ft_strcmp(cmd->argv[0], "cd") == 0 || ft_strcmp(cmd->argv[0],
			"export") == 0 || ft_strcmp(cmd->argv[0], "unset") == 0
		|| ft_strcmp(cmd->argv[0], "exit") == 0)
		return (1);
	return (0);
}

// exec les builtin qui change l'env dans le processus parent pas dans un fork
static int	exec_parent_builtin(t_cmd **cmds, int n, t_pipe *p, pid_t *pids)
{
	int	**fd;

	fd = p->fd;
	expand_vars_new(cmds[0]->argv, p->envp, p->last_exit, p);
	p->last_exit = exec_builtin(cmds[0]->argv, p);
	free_all_fd(fd, n - 1);
	free(pids);
	return (1);
}

// crée les processus enfant
static void	fork_children(t_pipe *p, pid_t *pids, int n)
{
	int	i;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	i = -1;
	while (++i < n)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			child_process(p, i);
		}
	}
}

// execute le pipe proprement avec les fonctions au dessus
void	execute_pipeline(t_cmd **cmds_meta, int n, char **envp, t_pipe *p)
{
	int		**fd;
	pid_t	*pids;

	fd = init_pipes(n);
	if (!fd)
		return ((void)(p->last_exit = 1));
	pids = malloc(sizeof(pid_t) * n);
	if (!pids)
	{
		free_all_fd(fd, n - 1);
		return ((void)(p->last_exit = 1));
	}
	p->cmds_meta = cmds_meta;
	init_pipeline_ctx(p, fd, n, envp);
	if (n == 1 && should_exec_in_parent(cmds_meta[0]))
		return ((void)exec_parent_builtin(cmds_meta, n, p, pids));
	fork_children(p, pids, n);
	close_all_pipes(fd, n - 1);
	wait_and_store_exit(p, pids, n);
	init_signals();
	free_all_fd(fd, n - 1);
	free(pids);
}
