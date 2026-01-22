/* Header */ 

#include "cub3D.h"

int main(int argc, char **argv)
{
    t_game game;
    int     fd;

    if (argc != 2)
        exit_error("Usage: ./cub3D map.cub\n", &game.map);

    fd = open_file(argv[1], &game.map);
    game.map = parse_entry_file(fd);
    close(fd);
    validate_all_elements(&game.map);
    textures_is_valid(game.map);
    validate_player_count(&game.map);
    validate_map_closed(&game.map);
    validate_map_spaces(&game.map);
    ft_putstr_fd("Parsing OK\n", 1);
    init_player(&game.map, &game.player);
    init_mlx(&game);
    load_textures(&game);
    ft_putstr_fd("Textures loaded\n", 1); // Step 3 initialization

    mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);

	mlx_loop(game.mlx);

    // Step 3 will continue here: render loop

    free_map(&game.map);
    return (0);
}

