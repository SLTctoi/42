/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:32:30 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:38:27 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	assign_texture_nswe(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "NO", 3))
	{
		if (!map->no)
			map->no = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
	if (!ft_strncmp(id, "SO", 3))
	{
		if (!map->so)
			map->so = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
	if (!ft_strncmp(id, "WE", 3))
	{
		if (!map->we)
			map->we = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
}

static void	assign_texture_ea(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "EA", 3))
	{
		if (!map->ea)
			map->ea = ft_strdup(value);
		else
			exit_error(ERROR_DUPLICATE, map);
	}
}

static void	assign_colors(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "F", 2) || !ft_strncmp(id, "C", 2))
		assign_color_value(id, value, map);
}

int	assign_value(char *identifier, char *value, t_map *map)
{
	assign_texture_nswe(identifier, value, map);
	assign_texture_ea(identifier, value, map);
	assign_colors(identifier, value, map);
	return (0);
}
