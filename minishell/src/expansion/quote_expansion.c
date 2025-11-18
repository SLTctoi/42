/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:23:09 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:23:16 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// gère chaque char de s en fonction de l'état des quotes
static void	process_char(const char *s, t_quote_state *st)
{
	if (s[st->i] == '\'' && !st->in_double)
	{
		st->in_single = !st->in_single;
		st->i++;
	}
	else if (s[st->i] == '"' && !st->in_single)
	{
		st->in_double = !st->in_double;
		st->i++;
	}
	else if (s[st->i] == '\\' && st->in_double && s[st->i + 1])
		handle_backslash(s, st);
	else if (s[st->i] == '$' && !st->in_single)
		expand_variable(s, st);
	else
	{
		append_char(&st->result, s[st->i]);
		st->i++;
	}
}

// parse s et expanse les variables en fonction des quotes
char	*parse_and_expand(const char *s, char **envp, int last_exit)
{
	t_quote_state	st;

	if (!s)
		return (NULL);
	ft_memset(&st, 0, sizeof(t_quote_state));
	st.envp = envp;
	st.last_exit = last_exit;
	st.result = ft_strdup("");
	if (!st.result)
		return (NULL);
	while (s[st.i])
		process_char(s, &st);
	return (st.result);
}

// parse_and_expand pour tous les argv
void	expand_vars_new(char **argv, char **envp, int last_exit)
{
	int		i;
	char	*exp;

	i = 0;
	while (argv[i])
	{
		exp = parse_and_expand(argv[i], envp, last_exit);
		if (exp)
		{
			free(argv[i]);
			argv[i] = exp;
		}
		i++;
	}
}
