/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:33:58 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:34:00 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	remove_last_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

char	**ft_realloc_map(char **old_map, int old_size, char *line, t_map *map)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (old_size + 2));
	if (!new_map)
		exit_error(NULL, map);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[old_size] = ft_strdup(line);
	if (!new_map[old_size])
		exit_error(NULL, map);
	remove_last_newline(new_map[old_size]);
	new_map[old_size + 1] = NULL;
	free(old_map);
	return (new_map);
}
