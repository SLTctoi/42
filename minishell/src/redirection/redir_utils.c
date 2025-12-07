/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:53:38 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/07 14:17:05 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Calcule la longueur totale d'un nom de fichier
// concaténé en sommant les longueurs des parties entre guillemets
static int	calc_concat_len(char ***cmds, int i, int start)
{
	char	*unquoted;
	int		total_len;
	int		m;

	total_len = 0;
	m = start;
	while (cmds[i][m] && (cmds[i][m][0] == '"' || cmds[i][m][0] == '\''))
	{
		unquoted = extract_quoted_content(cmds[i][m++]);
		if (unquoted)
		{
			total_len += ft_strlen(unquoted);
			free(unquoted);
		}
	}
	return (total_len);
}

// Construit un nom de fichier en concaténant
// les parties entre guillemets et avançant le pointeur
char	*build_concat_filename(char ***cmds, int i, int *j_ptr)
{
	char	*filename;
	char	*unquoted;
	int		n;

	filename = malloc(calc_concat_len(cmds, i, *j_ptr + 1) + 1);
	if (!filename)
		return (NULL);
	filename[0] = '\0';
	n = *j_ptr + 1;
	while (cmds[i][n] && (cmds[i][n][0] == '"' || cmds[i][n][0] == '\''))
	{
		unquoted = extract_quoted_content(cmds[i][n++]);
		if (unquoted)
		{
			ft_strlcat(filename, unquoted, calc_concat_len(cmds, i, *j_ptr + 1)
				+ 1);
			free(unquoted);
		}
	}
	*j_ptr = n;
	return (filename);
}

// Vérifie si les tokens suivants
// sont des parties consécutives entre guillemets
int	check_quoted_parts(char ***cmds, int i, int j)
{
	int	m;

	m = j + 1;
	while (cmds[i][m] && (cmds[i][m][0] == '"' || cmds[i][m][0] == '\''))
		m++;
	return (m > j + 1);
}

// Saute les tokens vides pour atteindre le prochain token valide
int	skip_to_next_token(char ***cmds, int i, int j)
{
	int	next_idx;

	next_idx = j + 1;
	while (cmds[i][next_idx] && cmds[i][next_idx][0] == '\0')
		next_idx++;
	return (next_idx);
}

// Crée un fichier de sortie en supprimant les guillemets
// et ouvrant avec les flags appropriés
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
