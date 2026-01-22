#include "cub3D.h"

static void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	y;
	int	color;

	color = (game->map.C[0] << 16) | (game->map.C[1] << 8) | game->map.C[2];
	y = 0;
	while (y < draw_start)
	{
		draw_pixel(game, x, y, color);
		y++;
	}
}

static void	draw_floor(t_game *game, int x, int draw_end)
{
	int	y;
	int	color;

	color = (game->map.F[0] << 16) | (game->map.F[1] << 8) | game->map.F[2];
	y = draw_end + 1;
	while (y < SCREEN_HEIGHT)
	{
		draw_pixel(game, x, y, color);
		y++;
	}
}

static void	init_texture_vars(t_game *game, t_ray *ray, int *tex_vars)
{
	t_texture	*tex;
	double		wall_x;

	tex = select_texture(game, ray);
	wall_x = calculate_wall_x(game, ray);
	tex_vars[0] = (int)(wall_x * tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_vars[0] = tex->width - tex_vars[0] - 1;
	tex_vars[1] = tex->height;
}

static void	draw_textured_wall(t_game *game, t_ray *ray, int x, int *dims)
{
	t_texture	*tex;
	int			tex_vars[2];
	double		step;
	double		tex_pos;
	int			y;
	int			tex_y;

	init_texture_vars(game, ray, tex_vars);
	tex = select_texture(game, ray);
	step = 1.0 * tex->height / dims[0];
	tex_pos = (dims[1] - SCREEN_HEIGHT / 2 + dims[0] / 2) * step;
	y = dims[1];
	while (y <= dims[2])
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		draw_pixel(game, x, y, get_texture_color(tex, tex_vars[0], tex_y));
		y++;
	}
}

void	render_wall_slice(t_game *game, t_ray *ray, int x)
{
	int	dims[3];

	dims[0] = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	dims[1] = -dims[0] / 2 + SCREEN_HEIGHT / 2;
	if (dims[1] < 0)
		dims[1] = 0;
	dims[2] = dims[0] / 2 + SCREEN_HEIGHT / 2;
	if (dims[2] >= SCREEN_HEIGHT)
		dims[2] = SCREEN_HEIGHT - 1;
	draw_ceiling(game, x, dims[1]);
	draw_textured_wall(game, ray, x, dims);
	draw_floor(game, x, dims[2]);
}
