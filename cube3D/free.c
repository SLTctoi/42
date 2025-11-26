#include "cub3D.h"

void    free_token(char **tok)
{
    int i;

    if (!tok)
        return ;
    i = 0;
    while (tok[i])
    {
        free(tok[i]);
        i++;
    }
    free(tok);
}
