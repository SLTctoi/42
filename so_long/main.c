#include "so_long.h"

int main(void)
{
    t_img img;
    char *map[] = {
        "111111",
        "10PC01",
        "100001",
        "1E0001",
        "111111",
        NULL
    };

    img.map = map;
    init_player_pos(&img);

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, 6 * 32, 6 * 32, "So_long"); // faire une taille dinamyque en fonction de la taille de la map



    load_img(&img);
    draw_map(&img, map);
    mlx_key_hook(img.win, key_hook, &img);

    mlx_loop(img.mlx);
    return (0);
}