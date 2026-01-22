/* header */

#include "cub3D.h"

void	draw_player(t_game *game)
{
	int	offset_x;
	int	offset_y;
	int	x;
	int	y;

	offset_x = (SCREEN_WIDTH - map_width(game)) / 2;
	offset_y = (SCREEN_HEIGHT - map_height(game)) / 2;
	x = offset_x + game->player.pos_x * TILE_SIZE;
	y = offset_y + game->player.pos_y * TILE_SIZE;
	draw_square(game, x - 3, y - 3, 0xFF0000);
}

static void	draw_line_pixels(t_game *game, int x0, int y0, int x1, int y1,
		int dx, int dy, int sx, int sy)
{
	int	err;
	int	e2;

	err = dx + dy;
	while (1)
	{
		draw_pixel(game, x0, y0, 0x0000FF); // Red for example
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;

	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	draw_line_pixels(game, x0, y0, x1, y1, dx, dy, sx, sy);
}

