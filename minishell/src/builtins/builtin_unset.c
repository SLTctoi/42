/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:20:04 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/07 13:44:53 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// reproduit la commande unset
int	builtin_unset(char **args, t_pipe *p)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (is_valid_var(args[i]))
			remove_env(&p->envp, args[i]);
		i++;
	}
	p->last_exit = 0;
	return (0);
}
