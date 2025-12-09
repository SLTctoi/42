/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:44:12 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 13:30:50 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	setup_heredoc_signals(struct sigaction *old_sa)
{
	struct sigaction	sa;

	sa.sa_handler = handle_heredoc_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, old_sa);
}

static int	process_heredoc_line(char *line, int fd_write, t_heredoc_ctx *ctx)
{
	char	*expanded;

	if (!line)
		return (0);
	if (ft_strcmp(line, ctx->clean_lim) == 0)
	{
		free(line);
		return (0);
	}
	if (ctx->should_expand)
	{
		expanded = expand_heredoc_line(line, ctx->p);
		free(line);
		if (expanded)
		{
			write(fd_write, expanded, ft_strlen(expanded));
			free(expanded);
		}
	}
	else
		write(fd_write, line, ft_strlen(line));
	if (!ctx->should_expand)
		free(line);
	write(fd_write, "\n", 1);
	return (1);
}

static int	handle_heredoc_interrupt(int *fd, t_heredoc_ctx *ctx,
		struct sigaction *old_sa)
{
	free(ctx->clean_lim);
	close(fd[1]);
	close(fd[0]);
	sigaction(SIGINT, old_sa, NULL);
	rl_done = 0;
	rl_replace_line("", 0);
	return (-1);
}

static int	read_heredoc_lines(int *fd, t_heredoc_ctx *ctx,
		struct sigaction *old_sa)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (g_signal == 130)
		{
			g_signal = 0;
			return (handle_heredoc_interrupt(fd, ctx, old_sa));
		}
		if (!line)
		{
			rl_free_line_state();
			rl_cleanup_after_signal();
			break ;
		}
		if (!process_heredoc_line(line, fd[1], ctx))
			break ;
	}
	return (fd[0]);
}

// implémente le <<
int	here_doc(char *limiter, t_pipe *p)
{
	int					fd[2];
	int					result;
	struct sigaction	old_sa;
	t_heredoc_ctx		ctx;

	if (pipe(fd) == -1)
		return (-1);
	ctx.p = p;
	ctx.should_expand = !has_quotes(limiter);
	ctx.clean_lim = remove_quotes((char *)limiter);
	setup_heredoc_signals(&old_sa);
	result = read_heredoc_lines(fd, &ctx, &old_sa);
	if (result != -1)
	{
		free(ctx.clean_lim);
		close(fd[1]);
	}
	sigaction(SIGINT, &old_sa, NULL);
	return (result);
}
