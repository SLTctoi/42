/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:28:57 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:29:30 by mchrispe         ###   ########.fr       */
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

// pour parse_outfile.c
int	attached_outfile(char ***cmds, t_cmd *cmd, int *j, t_out_params prm)
{
	if (!check_pipe_after_redir(cmds, prm.prm.i, *j, prm.prm.p))
		return (0);
	if (cmd->outfile && handle_prev_outfile(cmd, prm.prm.nb_cmds, prm.prm.p,
			prm.redir_error))
	{
		if (prm.prm.nb_cmds == 1)
			return (0);
		(*j)++;
		return (1);
	}
	set_outfile(cmd, cmds[prm.prm.i][*j]);
	if (!create_outfile(cmd->outfile, cmd->append, prm.prm.p, prm.prm.nb_cmds))
	{
		if (!outfile_error(prm.prm.nb_cmds, prm.redir_error))
			return (0);
	}
	(*j)++;
	return (1);
}
