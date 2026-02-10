/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:58:11 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:58:12 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	load_texture(t_game *game, t_texture *tex, char *path)
{
	if (!path || !*path)
	{
		ft_putstr_fd(ERROR_MISSING_TEXTURE, 2);
		close_window(game);
	}
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		ft_putstr_fd(ERROR_LOAD_TEXTURE, 2);
		ft_putendl_fd(path, 2);
		close_window(game);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
	{
		ft_putstr_fd(ERROR_TEXTURE_DATA, 2);
		close_window(game);
	}
}

void	load_textures(t_game *game)
{
	load_texture(game, &game->tex_no, game->map.no);
	load_texture(game, &game->tex_so, game->map.so);
	load_texture(game, &game->tex_we, game->map.we);
	load_texture(game, &game->tex_ea, game->map.ea);
}
