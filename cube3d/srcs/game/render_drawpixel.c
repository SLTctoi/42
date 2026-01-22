/* header */

#include "cub3D.h"

void	draw_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->screen.addr
		+ (y * game->screen.line_len + x * (game->screen.bpp / 8));
	*(unsigned int *)dst = color;
}
