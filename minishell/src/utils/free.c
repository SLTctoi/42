/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:00:07 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/10 11:10:01 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_triple_pointer(char ***ptr)
{
	int	i;
	int	j;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			free(ptr[i][j]);
			j++;
		}
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->argv)
		free_split(cmd->argv);
	if (cmd->infile)
		free(cmd->infile);
	if (cmd->outfile)
		free(cmd->outfile);
	if (cmd->heredoc)
		free(cmd->heredoc);
	if (cmd->heredoc_fd >= 0)
		close(cmd->heredoc_fd);
	free(cmd);
}

static void	cleanup_minishell_resources_utils(t_pipe *p)
{
	if (p->fd && p->n > 1)
	{
		free_all_fd(p->fd, p->n - 1);
		p->fd = NULL;
	}
	if (p->pids)
	{
		free(p->pids);
		p->pids = NULL;
	}
}

void	cleanup_minishell_resources(t_pipe *p)
{
	int	i;

	cleanup_minishell_resources_utils(p);
	if (p->cmds_meta && p->nb_cmds > 0)
	{
		i = -1;
		while (++i < p->nb_cmds)
			free_cmd(p->cmds_meta[i]);
		free(p->cmds_meta);
		p->cmds_meta = NULL;
	}
	if (p->cmds)
	{
		free_triple_pointer(p->cmds);
		p->cmds = NULL;
	}
	if (p->envp)
	{
		free_split(p->envp);
		p->envp = NULL;
	}
	p->nb_cmds = 0;
	rl_clear_history();
}
