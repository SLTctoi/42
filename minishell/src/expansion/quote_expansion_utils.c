/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:22:26 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:22:40 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// récupère la valeur d'une variable dans env
char	*get_val_env(const char *var, char **envp)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(var);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
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

// remplace $VAR ou $? par sa valeur d'env
void	expand_variable(const char *s, t_quote_state *st)
{
	char	var[4096];
	char	*val;
	int		k;

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
	k = 0;
	while (s[st->i] && (ft_isalnum(s[st->i]) || s[st->i] == '_'))
		var[k++] = s[st->i++];
	var[k] = '\0';
	val = get_val_env(var, st->envp);
	append_str(&st->result, val);
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
