/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:23:38 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/23 19:19:02 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// crée une struct t_cmd pour chaque commande et l'initialise
t_cmd	**init_cmds(char ***cmds, int nb_cmds, t_pipe *p)
{
	t_cmd		**cmds_res;
	int			i;
	int			redir_error;
	t_params	prm;

	cmds_res = malloc(sizeof(t_cmd *) * nb_cmds);
	if (!cmds_res)
		return (NULL);
	i = -1;
	prm.nb_cmds = nb_cmds;
	prm.p = p;
	while (++i < nb_cmds)
	{
		redir_error = 0;
		prm.i = i;
		cmds_res[i] = create_single_cmd(cmds, i, &redir_error, prm);
		if (!cmds_res[i])
			return (NULL);
	}
	return (cmds_res);
}

// init la struct principale du minishell
int	init_minishell(t_pipe *p, char **envp)
{
	g_signal = 0;
	init_signals();
	p->envp = copy_env(envp);
	if (!p->envp)
	{
		perror("copy_env");
		return (0);
	}
	p->size_envp = size_env(p->envp);
	p->last_exit = 0;
	p->var_not_found = 0;
	return (1);
}
