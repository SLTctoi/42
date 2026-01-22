#include "cub3D.h"

// mettre une fonction qui free si il faut free avant d'exit ??
void exit_error(char *msg, t_map *map)
{
    if (msg)
    {
        ft_putstr_fd(msg, 2);
    }
    else
	{
        perror("Error: ");
	}
	if (map)
		free_map(map);
	gnl_cleanup();
    exit(1);
}

void	error_xpm_ext(char *identifier, t_map *map)
{
	char	*error_msg;
	char	*temp;

	temp = ft_strjoin(ERROR_XPM_EXT, " ");
	error_msg = ft_strjoin(temp, identifier);
	free(temp);
	temp = ft_strjoin(error_msg, "\n");
	free(error_msg);
	exit_error(temp, map);
}

void	error_too_many_args(char *identifier, t_map *map)
{
	char	*error_msg;
	char	*temp;

	temp = ft_strjoin(ERROR_TOO_MANY_ARGS, " ");
	error_msg = ft_strjoin(temp, identifier);
	free(temp);
	temp = ft_strjoin(error_msg, "\n");
	free(error_msg);
	exit_error(temp, map);
}