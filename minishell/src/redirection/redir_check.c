#include "minishell.h"


// Assemble les parties du nom de fichier en supprimant les guillemets.
static char	*concat_filename_parts(char **parts)
{
	int		i;
	char	*res;
	char	*unquoted;
	char	*tmp;

	if (!parts || !*parts)
		return (NULL);
	res = ft_strdup("");
	if (!res)
		return (NULL);
	i = -1;
	while (parts[++i])
	{
		unquoted = remove_quotes(parts[i]);
		if (unquoted)
		{
			tmp = ft_strjoin(res, unquoted);
			free(res);
			free(unquoted);
			res = tmp;
			if (!res)
				return (NULL);
		}
	}
	return (res);
}

// Obtient le nom de fichier sans guillemets
static char	*get_unquoted_filename(const char *filename)
{
	char	**parts;
	char	*unquoted_file;

	if (ft_strchr(filename + 1, '"') || ft_strchr(filename + 1, '\''))
	{
		parts = ft_split_quote(filename, "");
		if (!parts)
			return (NULL);
		unquoted_file = concat_filename_parts(parts);
		free_split(parts);
	}
	else
		unquoted_file = remove_quotes((char *)filename);
	return (unquoted_file);
}

static void	print_file_error(char *file, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(msg, 2);
}


// Vérifie l'accès en lecture du fichier d'entrée.
int	check_infile_access(const char *filename)
{
	char	*unquoted_file;
	int		res;

	unquoted_file = get_unquoted_filename(filename);
	if (!unquoted_file)
	{
		ft_putstr_fd("minishell: malloc error\n", 2);
		return (0);
	}
	res = 1;
	if (access(unquoted_file, F_OK) != 0)
	{
		print_file_error(unquoted_file, ": No such file or directory\n");
		res = 0;
	}
	else if (access(unquoted_file, R_OK) != 0)
	{
		print_file_error(unquoted_file, ": Permission denied\n");
		res = 0;
	}
	free(unquoted_file);
	return (res);
}

// Tente de créer/ouvrir le fichier en mode écriture (append ou trunc).
int	try_create_file(char *unquoted_file, int append)
{
	int	fd;

	fd = open(unquoted_file, O_WRONLY | O_CREAT
			| (append ? O_APPEND : O_TRUNC), 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(unquoted_file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}
