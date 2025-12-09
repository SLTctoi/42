/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:10:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 11:32:30 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// vérifie les erreurs de syntaxe pour <<delimiter
int	check_heredoc_syntax(char *token, t_params prm)
{
	if (token[2] == '<')
	{
		ft_putstr_fd("syntax error near unexpected token `<'\n", 2);
		prm.p->last_exit = 2;
		return (0);
	}
	if (token[2] == '|')
	{
		error_syntax_pipe(prm);
		return (0);
	}
	if (token[2] == '\0')
	{
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
		prm.p->last_exit = 2;
		return (0);
	}
	return (1);
}

// met à jour heredoc_fd et heredoc dans cmd
void	update_heredoc_attached(t_cmd *cmd, int fd, char *delimiter)
{
	if (cmd->heredoc_fd >= 0)
		close(cmd->heredoc_fd);
	if (cmd->heredoc)
		free(cmd->heredoc);
	cmd->heredoc = ft_strdup(delimiter);
	cmd->heredoc_fd = fd;
}

// Vérifie s'il y a un pipe à la fin (sans commande après) pour parse.c
int	check_pipe_end(char *input, t_pipe *p)
{
	int		i;

	i = ft_strlen(input) - 1;
	while (i >= 0 && (input[i] == ' ' || input[i] == '\t' || input[i] == '\n'))
		i--;
	if (i < 0)
		return (1);
	if (input[i] == '|')
	{
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	return (1);
}
