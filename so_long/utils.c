#include "so_long.h"

void add_and_print_move(t_img *img)
{
    img->count_move++;
    ft_printf("Nombre de mouvement : %i\n", img->count_move);
}