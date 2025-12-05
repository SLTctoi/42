/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:49:09 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/05 12:15:28 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Supprime les guillemets du nom de fichier et retourne une copie propre
char	*get_clean_filename(char *filename)
{
	char	*clean;

	clean = remove_quotes(filename);
	if (!clean)
		clean = ft_strdup(filename);
	return (clean);
}

// Traite une redirection d'entrée simple en nettoyant
// le nom et validant si nécessaire
int	process_infile_simple(t_cmd *cmd, char *filename, int nb_cmds, t_pipe *p)
{
	char	*new_infile;
	char	*old_infile;

	new_infile = get_clean_filename(filename);
	if (!new_infile)
		return (0);
	old_infile = cmd->infile;
	cmd->infile = new_infile;
	if (!validate_infile(cmd->infile, p, nb_cmds))
	{
		if (old_infile)
			free(old_infile);
		if (nb_cmds > 1)
			return (1);
		return (0);
	}
	if (old_infile)
		free(old_infile);
	return (1);
}

// Traite une redirection d'entrée avec guillemets en construisant
// le nom de fichier et validant si nécessaire
static int	handle_quoted_infile(char ***cmds, t_cmd *cmd, int *j_ptr,
		t_params prm)
{
	char	*filename;
	char	*old_infile;

	filename = build_concat_filename(cmds, prm.i, j_ptr);
	if (!filename)
		return (0);
	old_infile = cmd->infile;
	cmd->infile = filename;
	if (!validate_infile(cmd->infile, prm.p, prm.nb_cmds))
	{
		if (old_infile)
			free(old_infile);
		if (prm.nb_cmds > 1)
			return (1);
		return (0);
	}
	if (old_infile)
		free(old_infile);
	return (1);
}

// Traite une redirection d'entrée en détectant les guillemets
// et appelant la fonction appropriée
int	handle_infile_redirect(char ***cmds, t_cmd *cmd, int *j_ptr, t_params prm)
{
	if (!cmds[prm.i][*j_ptr + 1] || !cmds[prm.i][*j_ptr + 1][0])
	{
		ft_putstr_fd("syntax ", 2);
		ft_putstr_fd("error near unexpected token `newline'\n", 2);
		prm.p->last_exit = 2;
		return (0);
	}
	if (check_quoted_parts(cmds, prm.i, *j_ptr))
		return (handle_quoted_infile(cmds, cmd, j_ptr, prm));
	if (!process_infile_simple(cmd, cmds[prm.i][*j_ptr + 1], prm.nb_cmds,
		prm.p))
		return (0);
	*j_ptr += 2;
	return (1);
}

// pour pipe
// attend la fin de tous les processus enfant et stock leur sortie
void	wait_and_store_exit(t_pipe *p, pid_t *pids, int n)
{
	int	status;
	int	i;
	int	last_exit_code;

	i = -1;
	last_exit_code = 0;
	while (++i < n)
	{
		if (pids[i] > 0)
		{
			waitpid(pids[i], &status, 0);
			if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == SIGINT)
					write(1, "\n", 1);
				else if (WTERMSIG(status) == SIGQUIT)
					write(1, "Quit (core dumped)\n", 19);
				last_exit_code = 128 + WTERMSIG(status);
			}
			else if (WIFEXITED(status))
				last_exit_code = WEXITSTATUS(status);
		}
	}
	p->last_exit = last_exit_code;
}
