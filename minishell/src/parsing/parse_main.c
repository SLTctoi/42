/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:28:57 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 19:15:23 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// crée une structure t_cmd qui comporte chaque commande
t_cmd	*create_single_cmd(char ***cmds, int i, int *redir_error, t_params prm)
{
	t_cmd				*cmd;
	int					j;
	int					arg_idx;
	t_process_params	pprm;

	cmd = init_cmd_struct();
	if (!cmd)
		return (NULL);
	j = count_args(cmds, i);
	cmd->argv = malloc(sizeof(char *) * (j + 1));
	if (!cmd->argv)
		return (free(cmd), NULL);
	init_argv(cmd->argv, j);
	arg_idx = 0;
	init_process_params(&pprm, prm, redir_error, &arg_idx);
	if (!process_all_redir(cmds, cmd, &pprm))
		return (free_cmd(cmd), NULL);
	return (cmd);
}

static int	attached_outfile_cond(char ***cmds, int *j, t_out_params prm)
{
	if (cmds[prm.prm.i][*j][1] == '>' && cmds[prm.prm.i][*j][2] == '>')
	{
		ft_putstr_fd("syntax error near unexpected token `>'\n", 2);
		prm.prm.p->last_exit = 2;
		return (1);
	}
	if ((cmds[prm.prm.i][*j][1] == '>' && cmds[prm.prm.i][*j][2] == '\0')
		|| (cmds[prm.prm.i][*j][1] == '\0'))
	{
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
		prm.prm.p->last_exit = 2;
		return (1);
	}
	return (0);
}

// pour parse_outfile.c
int	attached_outfile(char ***cmds, t_cmd *cmd, int *j, t_out_params prm)
{
	if (!check_pipe_after_redir(cmds, prm.prm.i, *j, prm.prm.p))
		return (0);
	if (attached_outfile_cond(cmds, j, prm))
		return (0);
	if (cmd->outfile && handle_prev_outfile(cmd, prm.prm.nb_cmds, prm.prm.p,
			prm.redir_error))
	{
		if (prm.prm.nb_cmds == 1)
			return (0);
		(*j)++;
		return (1);
	}
	if (cmd->outfile)
		free(cmd->outfile);
	set_outfile(cmd, cmds[prm.prm.i][*j]);
	if (!create_outfile(cmd->outfile, cmd->append, prm.prm.p, prm.prm.nb_cmds))
	{
		if (!outfile_error(prm.prm.nb_cmds, prm.redir_error))
			return (0);
	}
	(*j)++;
	return (1);
}
