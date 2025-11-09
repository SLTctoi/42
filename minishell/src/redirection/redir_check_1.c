#include "minishell.h"

// verifie les perm et ouvre le fichier de la bonne facon (append ou pas)
int	check_outfile_access(const char *filename, int append)
{
	char	*unquoted_file;
	int		result;

	unquoted_file = remove_quotes((char *)filename);
	if (!unquoted_file)
	{
		ft_putstr_fd("minishell: malloc error\n", 2);
		return (0);
	}
	result = 1;
	if (access(unquoted_file, F_OK) == 0 && access(unquoted_file, W_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(unquoted_file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		result = 0;
	}
	else
		result = try_create_file(unquoted_file, append);
	free(unquoted_file);
	return (result);
}

// verifie les permissions du repertoire parent du outfile
static int	check_outfile_dir(char *unquoted_outfile)
{
	char	*last_slash;
	char	*dir_path;

	last_slash = ft_strrchr(unquoted_outfile, '/');
	if (!last_slash)
		return (1);
	dir_path = ft_substr(unquoted_outfile, 0, last_slash - unquoted_outfile);
	if (dir_path && access(dir_path, W_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(dir_path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free(dir_path);
		return (0);
	}
	free(dir_path);
	return (1);
}

// valide l'outfile en verifiant dir et access
static int	validate_outfile(t_cmd *cmd)
{
	char	*unquoted_outfile;

	unquoted_outfile = remove_quotes(cmd->outfile);
	if (!unquoted_outfile)
	{
		ft_putstr_fd("minishell: malloc error\n", 2);
		return (0);
	}
	if (!check_outfile_dir(unquoted_outfile))
	{
		free(unquoted_outfile);
		return (0);
	}
	free(unquoted_outfile);
	if (!check_outfile_access(cmd->outfile, cmd->append))
		return (0);
	return (1);
}

// valide le heredoc en retirant les quotes
static int	validate_heredoc(t_cmd *cmd)
{
	char	*unquoted_heredoc;

	unquoted_heredoc = remove_quotes(cmd->heredoc);
	if (!unquoted_heredoc)
	{
		ft_putstr_fd("minishell: malloc error\n", 2);
		return (0);
	}
	free(unquoted_heredoc);
	return (1);
}


// verifie toutes les redirections d'une commande
int	check_redirections(t_cmd *cmd)
{
	if (cmd->infile)
	{
		if (!check_infile_access(cmd->infile))
			return (0);
	}
	if (cmd->outfile)
	{
		if (!validate_outfile(cmd))
			return (0);
	}
	if (cmd->heredoc)
	{
		if (!validate_heredoc(cmd))
			return (0);
	}
	return (1);
}
