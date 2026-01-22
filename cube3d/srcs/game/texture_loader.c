#include "cub3D.h"

static void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putendl_fd(path, 2);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
}

void	load_textures(t_game *game)
{
	load_texture(game, &game->tex_no, game->map.NO);
	load_texture(game, &game->tex_so, game->map.SO);
	load_texture(game, &game->tex_we, game->map.WE);
	load_texture(game, &game->tex_ea, game->map.EA);
}
