/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:18:03 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/15 14:29:22 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_remaining_buffer(char *buffer, int i)
{
	int		j;
	char	*s;	

	s = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!s)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	i++;
	while (buffer[i])
		s[j++] = buffer[i++];
	s[j] = '\0';
	free(buffer);
	if (s[0] == '\0')
	{
		free(s);
		return (NULL);
	}
	return (s);
}
