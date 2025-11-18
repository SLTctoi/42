/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:20:04 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:20:28 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// reproduit la commande unset
int	builtin_unset(char **args, t_pipe *p)
{
	int	i;
	int	err;

	i = 1;
	err = 0;
	while (args[i])
	{
		if (!is_valid_var(args[i]))
		{
			write(2, "unset: `", 8);
			write(2, args[i], ft_strlen(args[i]));
			write(2, "': not a valid identifier\n", 26);
			err = 1;
		}
		else
			remove_env(&p->envp, args[i]);
		i++;
	}
	p->last_exit = err;
	return (err);
}
