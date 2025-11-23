/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:55:43 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/23 19:12:53 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Gère une erreur de descripteur de fichier en ouvrant /dev/null et sortant
static void	handle_fd_error(int in_pipe, int std_fd)
{
	int	fd;

	if (in_pipe)
	{
		if (std_fd == 0)
			fd = open("/dev/null", O_RDONLY);
		else
			fd = open("/dev/null", O_WRONLY);
		if (fd >= 0)
		{
			dup2(fd, std_fd);
			close(fd);
		}
	}
	exit(1);
}

// Gère la redirection d'entrée en traitant heredoc ou fichier d'entrée
static void	handle_input_redir(t_cmd *cmd, int in_pipe)
{
	char	*file;
	int		fd;

	if (cmd->heredoc_fd >= 0)
	{
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		close(cmd->heredoc_fd);
		return ;
	}
	if (!cmd->infile)
		return ;
	file = remove_quotes(cmd->infile);
	if (!file && (perror("malloc"), 1))
		exit(1);
	fd = open(file, O_RDONLY);
	if (fd < 0 && (perror(file), free(file), 1))
		handle_fd_error(in_pipe, STDIN_FILENO);
	free(file);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

// Gère la redirection de sortie en ouvrant le fichier et dup2
static void	handle_output_redir(t_cmd *cmd, int in_pipe)
{
	char	*file;
	int		fd;
	int		flags;

	if (!cmd->outfile)
		return ;
	file = remove_quotes(cmd->outfile);
	if (!file && (perror("malloc"), 1))
		exit(1);
	if (cmd->append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd < 0 && (perror(file), free(file), 1))
		handle_fd_error(in_pipe, STDOUT_FILENO);
	free(file);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

// Gère les redirections en appelant les fonctions d'entrée et sortie
void	handle_redirs(t_cmd *cmd, int in_pipeline)
{
	handle_input_redir(cmd, in_pipeline);
	handle_output_redir(cmd, in_pipeline);
}
