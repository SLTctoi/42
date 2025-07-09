#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"

typedef struct s_map_object
{
    char empty;
    char wall;
    char item;
    char exit;
    char start;
    int nb_exit;
    int nb_start;
    int nb_item;
}               t_map_object;

typedef struct s_img
{
    void *empty;
    void *wall;
    void *item;
    void *exit;
    void *start;
}   t_img;

typedef struct s_map
{
    char **map;
    int height;
    int width;
    t_map_object object;
    t_img img;
}               t_map;

#endif SO_LONG_H