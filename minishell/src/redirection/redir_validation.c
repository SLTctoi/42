/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:54:43 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/07 12:14:53 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Vérifie si un fichier existe et gère les erreurs pour les commandes seules
int	check_file_exists(char *file, t_pipe *p, int nb_cmds)
{
	(void)nb_cmds;
	if (access(file, F_OK) != 0)
	{
		perror(file);
		p->last_exit = 1;
		return (0);
	}
	return (1);
}

// Vérifie si un fichier est lisible et gère les erreurs
// pour les commandes seules
int	check_file_readable(char *file, t_pipe *p, int nb_cmds)
{
	(void)nb_cmds;
	if (access(file, R_OK) != 0)
	{
		perror(file);
		p->last_exit = 1;
		return (0);
	}
	return (1);
}

// Valide un fichier d'entrée en vérifiant existence et permission de lecture
int	validate_infile(char *infile, t_pipe *p, int nb_cmds)
{
	if (access(infile, F_OK) != 0)
	{
		if (nb_cmds == 1)
		{
			perror(infile);
			p->last_exit = 1;
		}
		return (0);
	}
	if (access(infile, R_OK) != 0)
	{
		if (nb_cmds == 1)
		{
			perror(infile);
			p->last_exit = 1;
		}
		return (0);
	}
	return (1);
}
