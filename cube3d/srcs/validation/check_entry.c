#include "cub3D.h"

// i already check if .cub , can open file, if the map is only 0 1 N S E W space and \name
// i already check if no duplicate NO SO WE EA F C
// i already check if map is the last and ni empty line in the map
// i check if i have an element after NO SO WE ...


// je dois check que pour NO SO WE EA ca se termine bien par .xpm sinon error
// je dois check que pour F C c'est bien un code RGB en mode int,int,int

// parsing and texture_is_valid just after 

void textures_is_valid(t_map map)
{
    size_t len;

    len = ft_strlen(map.NO);
    if (len < 4)
        exit_error(ERROR_TEXTURE_PATH, &map);
    if (ft_strcmp(".xpm", map.NO + (len - 4)) != 0)
        error_xpm_ext("NO", &map);
    len = ft_strlen(map.SO);
    if (len < 4)
        exit_error(ERROR_TEXTURE_PATH, &map);
    if (ft_strcmp(".xpm", map.SO + (len - 4)) != 0)
        error_xpm_ext("SO", &map);
    len = ft_strlen(map.WE);
    if (len < 4)
        exit_error(ERROR_TEXTURE_PATH, &map);
    if (ft_strcmp(".xpm", map.WE + (len - 4)) != 0)
        error_xpm_ext("WE", &map);
    len = ft_strlen(map.EA);
    if (len < 4)
        exit_error(ERROR_TEXTURE_PATH, &map);
    if (ft_strcmp(".xpm", map.EA + (len - 4)) != 0)
        error_xpm_ext("EA", &map);
}
