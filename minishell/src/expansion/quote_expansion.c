/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:23:09 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/04 17:48:04 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// gère chaque char de s en fonction de l'état des quotes
static void	process_char(const char *s, t_quote_state *st, t_pipe *p)
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
		expand_variable(s, st, p);
	else
	{
		append_char(&st->result, s[st->i]);
		st->i++;
	}
}

// parse s et expanse les variables en fonction des quotes
char	*parse_and_expand(const char *s, char **envp, int last_exit, t_pipe *p)
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
		process_char(s, &st, p);
	return (st.result);
}

// gère le backslash dans les guillemets doubles
void	handle_backslash(const char *s, t_quote_state *st)
{
	st->i++;
	if (s[st->i] == '"' || s[st->i] == '\\' || s[st->i] == '$')
	{
		append_char(&st->result, s[st->i]);
		st->i++;
	}
	else
	{
		append_char(&st->result, '\\');
		append_char(&st->result, s[st->i]);
		st->i++;
	}
}
