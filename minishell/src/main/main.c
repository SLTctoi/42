/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:24:43 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/17 17:19:42 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_pipe	p;

	(void)ac;
	(void)av;
	if (!init_minishell(&p, envp))
		return (1);
	while (handle_input(&p))
		;
	cleanup_minishell_resources(&p);
	return (p.last_exit);
}
