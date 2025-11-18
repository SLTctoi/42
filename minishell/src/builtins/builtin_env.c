/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:16:24 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:16:37 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print un msg d'erreur si env a des args
static void	print_error_env(t_pipe *p, char *arg)
{
	write(2, "env: '", 6);
	write(2, arg, ft_strlen(arg));
	write(2, "': No such file or directory\n", 29);
	p->last_exit = 127;
}

// reproduit la commande env
int	builtin_env(char **args, t_pipe *p)
{
	int	i;

	if (args[1])
	{
		print_error_env(p, args[1]);
		return (p->last_exit);
	}
	i = 0;
	while (p->envp[i])
	{
		if (ft_strchr(p->envp[i], '='))
			ft_putendl_fd(p->envp[i], 1);
		i++;
	}
	p->last_exit = 0;
	return (p->last_exit);
}
