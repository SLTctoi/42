/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:19:41 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:22:09 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// reproduit la commande pwd
int	builtin_pwd(t_pipe *p, char **args)
{
	char	cwd[16384];

	(void)args;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (ft_strncmp(cwd, "/goinfre/mchrispe", 17) == 0)
		{
			ft_putstr_fd("/home/mchrispe/goinfre", 1);
			ft_putendl_fd(cwd + 17, 1);
		}
		else
		{
			ft_putendl_fd(cwd, 1);
		}
		p->last_exit = 0;
		return (0);
	}
	perror("pwd");
	p->last_exit = 1;
	return (1);
}
