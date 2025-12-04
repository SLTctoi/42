/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:30:20 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/04 18:01:03 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// gère les redirections <
int	handle_infile_redir(char ***cmds, t_cmd *cmd, int *j, t_params prm)
{
	if (ft_strcmp(cmds[prm.i][*j], "<") == 0)
	{
		if (!check_pipe_after_redir(cmds, prm.i, *j, prm.p))
			return (0);
		return (handle_infile_redirect(cmds, cmd, j, prm));
	}
	else if (cmds[prm.i][*j][0] == '<' && cmds[prm.i][*j][1] != '<')
	{
		if (cmds[prm.i][*j][1] == '|')
		{
			ft_putstr_fd("syntax error near unexpected ", 2);
			ft_putstr_fd("token `|'\n", 2);
			prm.p->last_exit = 2;
			return (0);
		}
		if (!process_infile_simple(cmd, cmds[prm.i][*j] + 1, prm.nb_cmds,
			prm.p))
			return (0);
		(*j)++;
		return (1);
	}
	return (1);
}

// traite un heredoc << et met à jour le fd
static int	process_heredoc_simple(char ***cmds, t_cmd *cmd,
	int *j, t_params prm)
{
	int	fd;

	if (!cmds[prm.i][*j + 1] || cmds[prm.i][*j + 1][0] == '|')
	{
		error_syntax_pipe(prm);
		return (0);
	}
	fd = here_doc(cmds[prm.i][*j + 1], prm.p);
	if (fd < 0)
	{
		if (g_signal == 130)
			prm.p->last_exit = 130;
		return (0);
	}
	if (cmd->heredoc_fd >= 0)
		close(cmd->heredoc_fd);
	if (cmd->heredoc)
		free(cmd->heredoc);
	cmd->heredoc = ft_strdup(cmds[prm.i][*j + 1]);
	cmd->heredoc_fd = fd;
	*j += 2;
	return (1);
}

// gère les redirection <<
int	handle_heredoc_redir(char ***cmds, t_cmd *cmd, int *j, t_params prm)
{
	if (ft_strcmp(cmds[prm.i][*j], "<<") == 0)
		return (process_heredoc_simple(cmds, cmd, j, prm));
	else if (cmds[prm.i][*j][0] == '<' && cmds[prm.i][*j][1] == '<')
		return (handle_heredoc_attached(cmds, cmd, j, prm));
	return (0);
}

// remplit argv avec les arf de la cmd
int	add_arg_to_argv(char ***argv_ptr, int *arg_idx, char *arg)
{
	(*argv_ptr)[*arg_idx] = ft_strdup(arg);
	if (!(*argv_ptr)[*arg_idx])
		return (0);
	(*arg_idx)++;
	return (1);
}

