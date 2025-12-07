/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:11 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/07 13:46:27 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// verifie si le nom de la var est valide
int	is_valid_var(char *var)
{
	int	i;

	if (!var || (!ft_isalpha(var[0]) && var[0] != '_'))
		return (0);
	i = 1;
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

// retire les guillemets de s pour exit
char	*strip_all_quotes(const char *s)
{
	int		i;
	int		j;
	char	*res;

	if (!s)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\'' && s[i] != '"')
			res[j++] = s[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}
