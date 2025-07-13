#include "so_long.h"
// !!! importer la lib minilibx
// !!! segfault si j'ai test.be et que je ./so_long test.ber
// !!! verif le nombre de sortie et de perso et de coin
// !!! taille dynamique su fenetre de base
// !!! probleme de free de 2 alloc ?? // normalemnt c bon
int main(int ac, char **av)
{
    t_img img;

    if (ac != 2 || !ber_extension(av[1]))
    {
        write(2, "Error\nUsage: ./so_long map.ber\n", 31);
        return (1);
    }
    img.map = parse_map(av[1]);
    init_player_pos(&img);
    init_exit_pos(&img);

    img.map_width = get_map_width(img.map);
    img.map_height = get_map_height(img.map);
    if (!check_map_access(&img))
    {
        write(2, "Error\nMap is not solvable\n", 26);
        final_free(img.map);
        return (1);
    }

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, 25 * 32, 25 * 32, "So_long"); // faire une taille dinamyque en fonction de la taille de la map
    is_rectangular(&img);
    load_img(&img);
    draw_map(&img, img.map);
    mlx_hook(img.win, 17, 0, close_window, &img);
    mlx_key_hook(img.win, key_hook, &img);
    mlx_expose_hook(img.win, resize_window, &img);
    mlx_loop(img.mlx);
    final_free(img.map);
    return (0);
}