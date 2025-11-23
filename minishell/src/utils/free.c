/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:00:07 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/23 19:12:53 by mchrispe         ###   ########.fr       */
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
