/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:45:21 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/10 13:43:44 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (fd)
		free_all_fd(fd, n - 1);
	if (pids)
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

// initialise les pipes et les pids pour le pipeline
static pid_t	*init_pipeline_resources(t_pipe *p, int n, int ***fd_out)
{
	int		**fd;
	pid_t	*pids;

	fd = NULL;
	if (n > 1)
	{
		fd = init_pipes(n);
		if (!fd)
		{
			p->last_exit = 1;
			return (NULL);
		}
	}
	pids = malloc(sizeof(pid_t) * n);
	if (!pids)
	{
		if (fd)
			free_all_fd(fd, n - 1);
		p->last_exit = 1;
		return (NULL);
	}
	*fd_out = fd;
	return (pids);
}

// execute le pipe proprement avec les fonctions au dessus
void	execute_pipeline(t_cmd **cmds_meta, int n, char **envp, t_pipe *p)
{
	p->pids = init_pipeline_resources(p, n, &p->fd);
	if (!p->pids)
		return ;
	p->cmds_meta = cmds_meta;
	init_pipeline_ctx(p, p->fd, n, envp);
	if (n == 1 && should_exec_in_parent(cmds_meta[0]))
		return ((void)exec_parent_builtin(cmds_meta, n, p, p->pids));
	fork_children(p, p->pids, n);
	if (p->fd)
		close_all_pipes(p->fd, n - 1);
	wait_and_store_exit(p, p->pids, n);
	init_signals();
	if (p->fd)
		free_all_fd(p->fd, n - 1);
	p->pids = NULL;
	p->fd = NULL;
}
