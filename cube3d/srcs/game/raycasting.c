#include "cub3D.h"

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_direction(&ray, &game->player, x);
		init_ray_delta(&ray);
		init_ray_step(&ray, &game->player);
		perform_dda(&ray, &game->map);
		calculate_wall_distance(&ray, &game->player);
		render_wall_slice(game, &ray, x);
		x++;
	}
}
