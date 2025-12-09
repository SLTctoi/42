/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:01:13 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:22:09 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Retire les guillemets englobants d'une chaîne
char	*strip_wrapping_quotes(const char *s)
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len >= 2 && ((s[0] == '"' && s[len - 1] == '"') || (s[0] == '\''
				&& s[len - 1] == '\'')))
	{
		res = malloc(len - 1);
		if (!res)
			return (NULL);
		i = 0;
		while (i < len - 2)
		{
			res[i] = s[i + 1];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (ft_strdup(s));
}
