#include "minishell.h"

// Gère le précédent outfile en ouvrant le fichier et gérant les erreurs
int	handle_prev_outfile(t_cmd *cmd, int nb_cmds, t_pipe *p,
		int *redir_error)
{
	char	*prev_file;
	int		tmp_fd;
	int		flags;

	prev_file = remove_quotes(cmd->outfile);
	if (!prev_file)
		return (1);
	flags = O_WRONLY | O_CREAT;
	if (cmd->append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	tmp_fd = open(prev_file, flags, 0644);
	if (tmp_fd < 0)
	{
		if (nb_cmds == 1)
			p->last_exit = 1;
		else
			*redir_error = 1;
	}
	else
		close(tmp_fd);
	free(prev_file);
	return (tmp_fd < 0);
}

// Crée un fichier de sortie en supprimant les guillemets et ouvrant avec les flags appropriés
int	create_outfile(char *outfile, int append, t_pipe *p, int nb_cmds)
{
	char	*new_file;
	int		tmp_fd;
	int		flags;

	new_file = remove_quotes(outfile);
	if (!new_file)
		return (0);
	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	tmp_fd = open(new_file, flags, 0644);
	if (tmp_fd < 0)
	{
		if (nb_cmds == 1)
			perror(new_file);
		free(new_file);
		p->last_exit = 1;
		return (0);
	}
	close(tmp_fd);
	free(new_file);
	return (1);
}

// Configure le fichier de sortie en libérant l'ancien et dupliquant le nouveau
static int	setup_outfile(char ***cmds, t_cmd *cmd, int next_idx,
		t_out_params prm)
{
	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = ft_strdup(cmds[prm.prm.i][next_idx]);
	cmd->append = prm.append;
	if (prm.prm.nb_cmds == 1 && !create_outfile(cmd->outfile,
			prm.append, prm.prm.p, prm.prm.nb_cmds))
		return (0);
	return (1);
}

// Gère une erreur du précédent outfile en mettant à jour les erreurs et avançant le pointeur
static int	handle_prev_out_error(t_cmd *cmd, int *j_ptr, int next_idx,
		t_out_params prm)
{
	if (prm.prm.nb_cmds > 1)
		*prm.redir_error = 1;
	*j_ptr = next_idx + 1;
	cmd->append = prm.append;
	if (prm.prm.nb_cmds == 1)
		return (0);
	else
		return (1);
}

// Traite une redirection de sortie en gérant les erreurs et configurant le fichier
int	handle_outfile_redirect(char ***cmds, t_cmd *cmd, int *j_ptr,
		t_out_params prm)
{
	int		next_idx;

	if (prm.redir_error && *prm.redir_error)
		return (*j_ptr += 2, 1);
	next_idx = skip_to_next_token(cmds, prm.prm.i, *j_ptr);
	if (!cmds[prm.prm.i][next_idx] || !cmds[prm.prm.i][next_idx][0])
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
		prm.prm.p->last_exit = 2;
		*prm.redir_error = 1;
		return (0);
	}
	if (cmd->outfile && handle_prev_outfile(cmd, prm.prm.nb_cmds,
			prm.prm.p, prm.redir_error))
		return (handle_prev_out_error(cmd, j_ptr, next_idx, prm));
	*j_ptr = next_idx + 1;
	return (setup_outfile(cmds, cmd, next_idx, prm));
}
