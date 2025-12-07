/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:40:15 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/07 14:12:15 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check si y'a pas une des cmds dans les pipes qui est vide
// et si ca commence pas par un pipe
static int	check_syntax_errors(char **cmd_tokens, t_pipe *p)
{
	if (!cmd_tokens || !cmd_tokens[0] || !cmd_tokens[0][0])
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	if (ft_strcmp(cmd_tokens[0], "|") == 0)
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	return (1);
}

// traite une commande dans un pipe
static int	process_single_cmd(char ***cmds, char **cmd_strs, int i, t_pipe *p)
{
	int		j;
	char	*s;
	char	**expanded;

	cmds[i] = ft_split_quote(cmd_strs[i], " \t");
	if (!cmds[i])
		return (0);
	expanded = expand_redirect_tokens(cmds[i]);
	if (!expanded)
		return (free_split(cmds[i]), 0);
	free_split(cmds[i]);
	cmds[i] = expanded;
	if (!check_syntax_errors(cmds[i], p))
		return (0);
	j = 0;
	while (cmds[i][j])
	{
		s = cmds[i][j];
		while (*s && *s != '\n')
			s++;
		*s = '\0';
		j++;
	}
	return (1);
}

// verifie si ca commence pas par un pipe
static int	check_pipe_start(char *input, t_pipe *p)
{
	char	*tmp;

	tmp = input;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp == '|')
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	return (1);
}

// gère toutes les commandes du pipe
static char	***process_all_cmds(char **cmd_strs, int nb_cmds, t_pipe *p)
{
	char	***cmds;
	int		i;

	cmds = malloc(sizeof(char **) * (nb_cmds + 1));
	if (!cmds)
		return (NULL);
	i = -1;
	while (++i < nb_cmds)
	{
		if (!process_single_cmd(cmds, cmd_strs, i, p))
		{
			while (i >= 0)
				free_split(cmds[i--]);
			free(cmds);
			return (NULL);
		}
	}
	cmds[i] = NULL;
	return (cmds);
}

// execute toutes les fonctions au dessus correctement
char	***parse_commands(char *input, int *nb_cmds, t_pipe *p)
{
	char	**cmd_strs;
	char	***cmds;

	if (!check_pipe_start(input, p))
		return (NULL);
	if (!check_pipe_end(input, p))
		return (NULL);
	cmd_strs = ft_split_quote(input, "|");
	if (!cmd_strs)
		return (NULL);
	*nb_cmds = 0;
	while (cmd_strs[*nb_cmds])
		(*nb_cmds)++;
	cmds = process_all_cmds(cmd_strs, *nb_cmds, p);
	free_split(cmd_strs);
	return (cmds);
}
