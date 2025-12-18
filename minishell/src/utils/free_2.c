/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:09:16 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/10 11:10:19 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cleanup_child_resources_utils(t_pipe *p)
{
	int	i;

	if (p->cmds_meta && p->nb_cmds > 0)
	{
		i = -1;
		while (++i < p->nb_cmds)
			free_cmd(p->cmds_meta[i]);
		free(p->cmds_meta);
		p->cmds_meta = NULL;
	}
}

void	cleanup_child_resources(t_pipe *p)
{
	int	i;

	cleanup_child_resources_utils(p);
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
	rl_clear_history();
}
