/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:33:04 by bvan-duy          #+#    #+#             */
/*   Updated: 2026/02/09 22:07:50 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parse_extract_value(t_parse_ctx *ctx)
{
	ctx->pos = 0;
	ctx->identifier = extract_identifier(ctx->line, &ctx->pos);
	if (!ctx->identifier || !is_valid_identifier(ctx->identifier))
	{
		if (ctx->identifier)
			free(ctx->identifier);
		ft_putstr_fd(ERROR_UNKNOWN_KEY, 2);
		return (0);
	}
	ctx->map->tmp_identifier = ctx->identifier;
	if (!ft_strcmp(ctx->identifier, "F") || !ft_strcmp(ctx->identifier, "C"))
		ctx->value = extract_color_value(ctx->line, &ctx->pos, ctx->map);
	else
		ctx->value = extract_value_with_quotes(ctx->line, &ctx->pos, ctx->map);
	if (!ctx->value)
	{
		free(ctx->identifier);
		ctx->map->tmp_identifier = NULL;
		ft_putstr_fd(ERROR_LINE_FORMAT, 2);
		return (0);
	}
	ctx->map->tmp_value = ctx->value;
	return (1);
}

static int	parse_check_and_assign(t_parse_ctx *ctx)
{
	if (check_no_extra_args(ctx->line, &ctx->pos, ctx->identifier) != 0)
	{
		free(ctx->identifier);
		free(ctx->value);
		ctx->map->tmp_identifier = NULL;
		ctx->map->tmp_value = NULL;
		return (1);
	}
	if (assign_value(ctx->identifier, ctx->value, ctx->map) != 0)
	{
		free(ctx->identifier);
		free(ctx->value);
		ctx->map->tmp_identifier = NULL;
		ctx->map->tmp_value = NULL;
		return (1);
	}
	free(ctx->identifier);
	free(ctx->value);
	ctx->map->tmp_identifier = NULL;
	ctx->map->tmp_value = NULL;
	return (0);
}

int	parse_config_line(char *line, t_map *map)
{
	t_parse_ctx	ctx;

	ctx.map = map;
	ctx.line = line;
	ctx.identifier = NULL;
	ctx.value = NULL;
	ctx.pos = 0;
	if (!parse_extract_value(&ctx))
		return (1);
	return (parse_check_and_assign(&ctx));
}

int	its_map(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	parse_non_map_line(char *line, t_map *map, int map_started)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\n')
			break ;
		i++;
	}
	if (line[i] == '\0')
		return (0);
	if (map_started)
	{
		ft_putstr_fd(ERROR_INVALID_MAP_CHAR, 2);
		return (1);
	}
	if (parse_config_line(line, map))
		return (1);
	return (0);
}
