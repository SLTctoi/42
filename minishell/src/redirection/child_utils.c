/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:33:22 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:22:09 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ferme tous les heredoc_fd sauf celui de la commande courante
static void	close_other_heredocs(t_pipe *p, int current_cmd)
{
	int	j;

	j = 0;
	while (j < p->n)
	{
		if (j != current_cmd && p->cmds_meta[j]->heredoc_fd >= 0)
			close(p->cmds_meta[j]->heredoc_fd);
		j++;
	}
}

// setup les in/out pour un processus enfant
void	setup_child(t_pipe *p, int i, t_cmd *cmd, int in_pipeline)
{
	if (i > 0)
		dup2(p->fd[i - 1][0], STDIN_FILENO);
	if (i < p->n - 1)
		dup2(p->fd[i][1], STDOUT_FILENO);
	close_all_pipes(p->fd, p->n - 1);
	close_other_heredocs(p, i);
	handle_redirs(cmd, in_pipeline);
}
