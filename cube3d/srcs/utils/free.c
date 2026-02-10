/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:21:39 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:21:40 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_token(char **tok)
{
	int	i;

	if (!tok)
		return ;
	i = 0;
	while (tok[i])
	{
		free(tok[i]);
		i++;
	}
	free(tok);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	free(map->no);
	map->no = NULL;
	free(map->so);
	map->so = NULL;
	free(map->we);
	map->we = NULL;
	free(map->ea);
	map->ea = NULL;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}
