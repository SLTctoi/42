/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:30:20 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/03 21:35:05 by mchrispe         ###   ########.fr       */
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

// gère les redirection <<
int	handle_heredoc_redir(char ***cmds, t_cmd *cmd, int *j, t_params prm)
{
	int	fd;

	if (ft_strcmp(cmds[prm.i][*j], "<<") == 0)
	{
		if (!cmds[prm.i][*j + 1] || cmds[prm.i][*j + 1][0] == '|')
		{
			error_syntax_pipe(prm);
			return (0);
		}
		fd = here_doc(cmds[prm.i][*j + 1]);
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

// appelle la bonne fonction en fonction de la redirection
int	process_single_redir(char ***cmds, t_cmd *cmd, int *j,
		t_process_params *prm)
{
	char	*tok;

	tok = cmds[prm->p.i][*j];
	if (tok[0] == '<' && tok[1] == '<')
	{
		if (!handle_heredoc_redir(cmds, cmd, j, prm->p))
			return (0);
		return (1);
	}
	if (!handle_infile_redir(cmds, cmd, j, prm->p))
		return (0);
	if (tok[0] == '<')
		return (1);
	if (!outfile_redir(cmds, cmd, j, prm->out))
		return (0);
	if (tok[0] == '>')
		return (1);
	if (!add_arg_to_argv(&cmd->argv, prm->arg_idx, tok))
		return (0);
	(*j)++;
	return (1);
}

// traite toutes les redirections d'une commande
int	process_all_redir(char ***cmds, t_cmd *cmd, t_process_params *prm)
{
	int	j;

	j = 0;
	while (cmds[prm->p.i][j])
	{
		if (!process_single_redir(cmds, cmd, &j, prm))
			return (0);
	}
	cmd->argv[*prm->arg_idx] = NULL;
	return (1);
}
