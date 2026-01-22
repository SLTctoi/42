#include "cub3D.h"

t_texture	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x < 0)
			return (&game->tex_no);
		else
			return (&game->tex_so);
	}
	else
	{
		if (ray->step_y < 0)
			return (&game->tex_we);
		else
			return (&game->tex_ea);
	}
}

double	calculate_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= (int)wall_x;
	return (wall_x);
}

int	get_texture_color(t_texture *tex, int tex_x, int tex_y)
{
	char	*pixel;

	pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(int *)pixel);
}
