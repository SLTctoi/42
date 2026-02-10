/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:23:59 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:30:01 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dir_north(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = -1;
	p->plane_x = 0.66;
	p->plane_y = 0;
}

void	dir_south(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = 1;
	p->plane_x = -0.66;
	p->plane_y = 0;
}

void	dir_east(t_player *p)
{
	p->dir_x = 1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0.66;
}

void	dir_west(t_player *p)
{
	p->dir_x = -1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = -0.66;
}
