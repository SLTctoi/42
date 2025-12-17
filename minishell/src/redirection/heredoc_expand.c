/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:30:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/17 17:34:29 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// verifie si le delimiteur contient des quotes
int	has_quotes(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

// expanse les variables dans une ligne de heredoc
char	*expand_heredoc_line(char *line, t_pipe *p)
{
	char	*expanded;

	if (!line)
		return (NULL);
	expanded = parse_and_expand(line, p->envp, p->last_exit, p);
	return (expanded);
}

// handler pour le signal SIGINT dans un heredoc
void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_signal = 130;
	write(1, "^C", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
}
