/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:16:57 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:17:02 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
** Helper: check a single texture path for validity
*/
static void	check_texture(char *path, char *id, t_map *map)
{
	size_t	len;

	if (!path)
		exit_error(ERROR_TEXTURE_PATH, map);
	len = ft_strlen(path);
	if (len < 4)
		exit_error(ERROR_TEXTURE_PATH, map);
	if (ft_strcmp(".xpm", path + (len - 4)) != 0)
		error_xpm_ext(id, map);
}

/*
** Validate all four wall textures in the map
*/
void	textures_is_valid(t_map *map)
{
	check_texture(map->no, "NO", map);
	check_texture(map->so, "SO", map);
	check_texture(map->we, "WE", map);
	check_texture(map->ea, "EA", map);
}
