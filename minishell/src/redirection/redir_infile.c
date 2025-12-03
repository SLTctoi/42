/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:49:09 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/03 23:08:08 by mchrispe         ###   ########.fr       */
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
	if (nb_cmds == 1 && !cmd->heredoc && !validate_infile(cmd->infile, p,
			nb_cmds))
	{
		if (old_infile)
			free(old_infile);
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
	if (prm.nb_cmds == 1 && !cmd->heredoc)
	{
		if (!validate_infile(cmd->infile, prm.p, prm.nb_cmds))
		{
			if (old_infile)
				free(old_infile);
			return (0);
		}
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
