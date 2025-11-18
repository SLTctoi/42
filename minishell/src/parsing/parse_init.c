/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:27:55 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:28:40 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// init un t_cmd NULL
t_cmd	*init_cmd_struct(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->heredoc = NULL;
	cmd->append = 0;
	cmd->argv = NULL;
	return (cmd);
}

// init argv à NULL
void	init_argv(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i <= argc)
		argv[i++] = NULL;
}

// init les params pour le process
void	init_process_params(t_process_params *pprm, t_params prm,
		int *redir_error, int *arg_idx)
{
	pprm->p = prm;
	pprm->out.prm = prm;
	pprm->out.redir_error = redir_error;
	pprm->out.append = 0;
	pprm->arg_idx = arg_idx;
}

// verif si un des tokens est > < >> <<
static int	is_skip_token(char *tok)
{
	if (ft_strcmp(tok, "<") == 0 || ft_strcmp(tok, ">") == 0)
		return (1);
	if (ft_strcmp(tok, ">>") == 0 || ft_strcmp(tok, "<<") == 0)
		return (1);
	if (tok[0] == '<' || tok[0] == '>')
		return (1);
	return (0);
}

// compte le nombre d'arg (sans les redirections)
int	count_args(char ***cmds, int i)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (cmds[i] && cmds[i][j])
	{
		if (is_skip_token(cmds[i][j]))
		{
			if ((ft_strcmp(cmds[i][j], "<") == 0 || ft_strcmp(cmds[i][j],
				">") == 0 || ft_strcmp(cmds[i][j], ">>") == 0
					|| ft_strcmp(cmds[i][j], "<<") == 0) && cmds[i][j + 1])
				j++;
			j++;
		}
		else
		{
			count++;
			j++;
		}
	}
	return (count);
}
