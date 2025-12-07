/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:39:39 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/07 14:09:23 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// vérifie qu'il n'y a pas de | après une redirection (pas de >|)
int	check_pipe_after_redir(char ***cmds, int i, int j, t_pipe *p)
{
	if (cmds[i][j + 1] && cmds[i][j + 1][0] == '|')
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	if (cmds[i][j][1] == '|' || (cmds[i][j][1] == '>' && cmds[i][j][2] == '|'))
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	return (1);
}

void	error_syntax_pipe(t_params prm)
{
	ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
	prm.p->last_exit = 2;
}

//condition pour handle_heredoc_redir
int	handle_heredoc_attached(char ***cmds, t_cmd *cmd, int *j, t_params prm)
{
	int	fd;

	if (!check_heredoc_syntax(cmds[prm.i][*j], prm))
		return (0);
	fd = here_doc(cmds[prm.i][*j] + 2, prm.p);
	if (fd < 0)
	{
		if (g_signal == 130)
			prm.p->last_exit = 130;
		return (0);
	}
	update_heredoc_attached(cmd, fd, cmds[prm.i][*j] + 2);
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
