#include "cub3D.h"

// mettre une fonction qui free si il faut free avant d'exit ??
void exit_error(char *msg)
{
    if (msg)
    {
        ft_putstr_fd(msg, 2);
    }
    else
        perror("Error: ");
    exit(1);
}