/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-duy <bvan-duy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:21:21 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/04 12:21:23 by bvan-duy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg, t_map *map)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	else
		perror("Error");
	if (map)
	{
		if (map->fd != -1)
			close(map->fd);
		if (map->gnl_buffer)
			free(map->gnl_buffer);
		if (map->tmp_identifier)
			free(map->tmp_identifier);
		if (map->tmp_value)
			free(map->tmp_value);
		if (map->current_line)
			free(map->current_line);
		if (map->tmp_split)
			free_token(map->tmp_split);
		free_map(map);
	}
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
	free(temp);
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
	free(temp);
}
