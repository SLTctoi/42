/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:39:39 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:40:04 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// vérifie qu'il n'y a pas de | après une redirection (pas de >|)
int	check_pipe_after_redir(char ***cmds, int i, int j, t_pipe *p)
{
	if (cmds[i][j + 1] && cmds[i][j + 1][0] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	if (cmds[i][j][1] == '|' || (cmds[i][j][1] == '>' && cmds[i][j][2] == '|'))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	return (1);
}

void	error_syntax_pipe(t_params prm)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	prm.p->last_exit = 2;
}
