/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:04:33 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/26 00:17:10 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	ft_fill_result(char **result, const char *s, char *delim)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s && is_delimiter(*s, delim))
			s++;
		start = s;
		while (*s && !is_delimiter(*s, delim))
			s++;
		if (s > start)
		{
			result[i++] = ft_strndup(start, s - start);
			if (!result[i - 1])
				return (ft_free_split(result, i - 1), 0);
		}
	}
	result[i] = NULL;
	return (1);
}