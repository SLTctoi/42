/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:17:57 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:18:01 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_all_elements(t_map *map)
{
	if (!map->no)
		exit_error(ERROR_MISSING_NO, map);
	if (!map->so)
		exit_error(ERROR_MISSING_SO, map);
	if (!map->we)
		exit_error(ERROR_MISSING_WE, map);
	if (!map->ea)
		exit_error(ERROR_MISSING_EA, map);
	if (!map->f_set)
		exit_error(ERROR_MISSING_F, map);
	if (!map->c_set)
		exit_error(ERROR_MISSING_C, map);
	if (!map->map)
		exit_error(ERROR_MISSING_MAP, map);
}
