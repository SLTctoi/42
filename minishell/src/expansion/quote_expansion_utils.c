/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:22:26 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/04 17:47:57 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// récupère la valeur d'une variable dans env
char	*get_val_env(const char *var, char **envp, t_pipe *p)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(var);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, len) == 0 && envp[i][len] == '=')
		{
			if (envp[i][len + 1] == '\0')
				p->var_not_found = 1;
			else
				p->var_not_found = 0;
			return (envp[i] + len + 1);
		}
		i++;
	}
	p->var_not_found = 1;
	return ("");
}

// append un str à res
void	append_str(char **res, const char *str)
{
	char	*tmp;

	if (!str || !*str)
		return ;
	if (!*res)
		*res = ft_strdup(str);
	else
	{
		tmp = ft_strjoin(*res, str);
		free(*res);
		*res = tmp;
	}
}

// append un char a res
void	append_char(char **res, char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	append_str(res, str);
}

// extrait le nom de variable et l'expanse
static void	expand_var_name(const char *s, t_quote_state *st, t_pipe *p)
{
	char	var[4096];
	char	*val;
	int		k;

	if (!st->in_single && !st->in_double)
		st->has_unquoted_var = 1;
	k = 0;
	while (s[st->i] && (ft_isalnum(s[st->i]) || s[st->i] == '_'))
		var[k++] = s[st->i++];
	var[k] = '\0';
	val = get_val_env(var, st->envp, p);
	append_str(&st->result, val);
}

// remplace $VAR ou $? par sa valeur d'env
void	expand_variable(const char *s, t_quote_state *st, t_pipe *p)
{
	char	*val;

	st->i++;
	if (s[st->i] == '?')
	{
		val = ft_itoa(st->last_exit);
		append_str(&st->result, val);
		free(val);
		st->i++;
		return ;
	}
	if (!ft_isalnum(s[st->i]) && s[st->i] != '_')
	{
		append_char(&st->result, '$');
		return ;
	}
	expand_var_name(s, st, p);
}
