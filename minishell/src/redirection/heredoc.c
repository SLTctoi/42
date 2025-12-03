/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:44:12 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/03 21:35:05 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_signal = 130;
	rl_done = 1;
}

static void	setup_heredoc_signals(struct sigaction *old_sa)
{
	struct sigaction	sa;

	sa.sa_handler = handle_heredoc_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, old_sa);
}

static int	process_heredoc_line(char *line, char *limiter, int fd_write)
{
	if (!line)
	{
		if (g_signal == 130)
			return (0);
		return (0);
	}
	if (ft_strcmp(line, limiter) == 0)
	{
		free(line);
		return (0);
	}
	write(fd_write, line, ft_strlen(line));
	write(fd_write, "\n", 1);
	free(line);
	return (1);
}

// implémente le <<
int	here_doc(char *limiter)
{
	int					fd[2];
	char				*line;
	struct sigaction	old_sa;

	if (pipe(fd) == -1)
		return (-1);
	setup_heredoc_signals(&old_sa);
	while (1)
	{
		line = readline("> ");
		if (g_signal == 130)
		{
			close(fd[1]);
			close(fd[0]);
			sigaction(SIGINT, &old_sa, NULL);
			rl_done = 0;
			return (-1);
		}
		if (!process_heredoc_line(line, limiter, fd[1]))
			break ;
	}
	close(fd[1]);
	sigaction(SIGINT, &old_sa, NULL);
	return (fd[0]);
}
