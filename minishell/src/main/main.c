/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:24:43 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/24 10:45:59 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

int	main(int ac, char **av, char **envp)
{
	t_pipe	p;

	(void)ac;
	(void)av;
	if (!init_minishell(&p, envp))
		return (1);
	while (handle_input(&p))
		;
	rl_clear_history();
	free_split(p.envp);
	return (0);
}
