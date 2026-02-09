/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:32:30 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/09 22:07:50 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_identifier(char *identifier)
{
	if (!identifier)
		return (0);
	if (!ft_strcmp(identifier, "NO") || !ft_strcmp(identifier, "SO")
		|| !ft_strcmp(identifier, "WE") || !ft_strcmp(identifier, "EA")
		|| !ft_strcmp(identifier, "F") || !ft_strcmp(identifier, "C"))
		return (1);
	return (0);
}

static int	check_duplicate(char *id, t_map *map)
{
	if (!ft_strcmp(id, "NO") && map->no)
		return (1);
	if (!ft_strcmp(id, "SO") && map->so)
		return (1);
	if (!ft_strcmp(id, "WE") && map->we)
		return (1);
	if (!ft_strcmp(id, "EA") && map->ea)
		return (1);
	if (!ft_strcmp(id, "F") && map->f_set)
		return (1);
	if (!ft_strcmp(id, "C") && map->c_set)
		return (1);
	return (0);
}

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

static void	assign_textures(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "NO", 3))
		map->no = ft_strdup(value);
	if (!ft_strncmp(id, "SO", 3))
		map->so = ft_strdup(value);
	if (!ft_strncmp(id, "WE", 3))
		map->we = ft_strdup(value);
	if (!ft_strncmp(id, "EA", 3))
		map->ea = ft_strdup(value);
	if (!ft_strncmp(id, "F", 2) || !ft_strncmp(id, "C", 2))
		assign_color_value(id, value, map);
}

int	assign_value(char *identifier, char *value, t_map *map)
{
	if (check_duplicate(identifier, map))
	{
		ft_putstr_fd(ERROR_DUPLICATE, 2);
		return (1);
	}
	assign_textures(identifier, value, map);
	return (0);
}
