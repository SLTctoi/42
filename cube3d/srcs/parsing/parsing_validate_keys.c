/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_keys.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:00:00 by mchrispe          #+#    #+#             */
/*   Updated: 2026/02/10 00:00:00 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_key(char *key)
{
	if (!key)
		return (0);
	if (!ft_strcmp(key, "NO"))
		return (1);
	if (!ft_strcmp(key, "SO"))
		return (1);
	if (!ft_strcmp(key, "WE"))
		return (1);
	if (!ft_strcmp(key, "EA"))
		return (1);
	if (!ft_strcmp(key, "F"))
		return (1);
	if (!ft_strcmp(key, "C"))
		return (1);
	return (0);
}

int	is_duplicate_key(char *key, t_map *map)
{
	if (!key)
		return (0);
	if (!ft_strcmp(key, "NO") && map->no)
		return (1);
	if (!ft_strcmp(key, "SO") && map->so)
		return (1);
	if (!ft_strcmp(key, "WE") && map->we)
		return (1);
	if (!ft_strcmp(key, "EA") && map->ea)
		return (1);
	if (!ft_strcmp(key, "F") && map->f_set)
		return (1);
	if (!ft_strcmp(key, "C") && map->c_set)
		return (1);
	return (0);
}

void	validate_key(char *key, t_map *map)
{
	if (!is_valid_key(key))
	{
		ft_putstr_fd("Error: Unknown key '", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("'\n", 2);
		exit_error("", map);
	}
	if (is_duplicate_key(key, map))
	{
		ft_putstr_fd("Error: Duplicate key '", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("'\n", 2);
		exit_error("", map);
	}
}
