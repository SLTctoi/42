/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:13 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/14 14:10:14 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_exit(t_img *img)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_player(t_img *img)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
