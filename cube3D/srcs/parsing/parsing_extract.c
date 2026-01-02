#include "cub3D.h"

static char	*extract_quoted_value(char *line, int *pos)
{
	char	*value;
	int		start;
	int		end;

	(*pos)++;
	start = *pos;
	while (line[*pos] && line[*pos] != '"')
		(*pos)++;
	if (!line[*pos])
		exit_error(ERROR_LINE_FORMAT);
	end = *pos;
	(*pos)++;
	value = ft_substr(line, start, end - start);
	return (value);
}

static char	*extract_unquoted_value(char *line, int *pos)
{
	char	*value;
	int		start;
	int		end;

	start = *pos;
	while (line[*pos] && !ft_iswhitespace(line[*pos])
		&& line[*pos] != '\n')
		(*pos)++;
	end = *pos;
	value = ft_substr(line, start, end - start);
	return (value);
}

char	*extract_value_with_quotes(char *line, int *pos)
{
	char	*value;

	while (ft_iswhitespace(line[*pos]))
		(*pos)++;
	if (!line[*pos])
		exit_error(ERROR_LINE_FORMAT);
	if (line[*pos] == '"')
		value = extract_quoted_value(line, pos);
	else
		value = extract_unquoted_value(line, pos);
	return (value);
}

char	*extract_value_no_quotes(char *line, int *pos)
{
	char	*value;

	while (ft_iswhitespace(line[*pos]))
		(*pos)++;
	if (!line[*pos])
		exit_error(ERROR_LINE_FORMAT);
	if (line[*pos] == '"')
		exit_error(ERROR_LINE_FORMAT);
	value = extract_unquoted_value(line, pos);
	return (value);
}

char	*extract_identifier(char *line, int *pos)
{
	char	*identifier;
	int		start;

	*pos = 0;
	while (ft_iswhitespace(line[*pos]))
		(*pos)++;
	if (!line[*pos])
		return (NULL);
	start = *pos;
	while (line[*pos] && !ft_iswhitespace(line[*pos]))
		(*pos)++;
	identifier = ft_substr(line, start, *pos - start);
	return (identifier);
}
