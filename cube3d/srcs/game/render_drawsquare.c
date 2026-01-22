/* header */
#include "cub3D.h"

void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			draw_pixel(game, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
