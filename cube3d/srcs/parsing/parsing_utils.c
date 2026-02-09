/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:34:09 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/06 12:44:49 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_map_lines(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_no_extra_args(char *line, int *pos, char *identifier)
{
	char	msg[128];

	while (line[*pos] && (ft_iswhitespace(line[*pos]) || line[*pos] == '\r'))
		(*pos)++;
	if (line[*pos] == '\0' || line[*pos] == '\n' || line[*pos] == '\r')
		return (0);
	snprintf(msg,
		sizeof(msg),
		"Error: Too many arguments for %s\n",
		identifier);
	ft_putstr_fd(msg, 2);
	return (1);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	return (i);
}

int	has_isolated_ones_at_start(char *str)
{
	int	i;
	int	ones_count;
	int	spaces_after;

	i = 0;
	i += skip_whitespace(str);
	ones_count = 0;
	while (str[i] == '1')
	{
		ones_count++;
		i++;
	}
	if (ones_count == 0 || ones_count >= 3)
		return (0);
	spaces_after = 0;
	while (str[i] == ' ')
	{
		spaces_after++;
		i++;
	}
	if (spaces_after >= 3 && str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}

void	check_map_chars(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ' && str[i] != '\n')
			exit_error(ERROR_INVALID_MAP_CHAR, map);
		i++;
	}
}
