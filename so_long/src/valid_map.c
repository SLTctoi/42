/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:13 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/16 14:12:46 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	count_item(t_img *img)
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
			if (img->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
