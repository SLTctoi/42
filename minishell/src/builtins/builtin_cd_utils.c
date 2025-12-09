/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:59:55 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:21:36 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Gère le cas "cd -" -> change de répertoire pour aller dans OLDPWD
int	cd_minus(t_pipe *p)
{
	char	*path;
	int		idx;

	idx = index_env(p->envp, "OLDPWD");
	if (idx >= 0)
		path = ft_strchr(p->envp[idx], '=') + 1;
	else
		path = NULL;
	if (!path)
		return (write(2, "cd: OLDPWD not set\n", 19), 1);
	if (change_directory(p, path) == 0)
	{
		idx = index_env(p->envp, "PWD");
		if (idx >= 0)
		{
			path = ft_strchr(p->envp[idx], '=') + 1;
			write(1, path, ft_strlen(path));
			write(1, "\n", 1);
		}
	}
	return (0);
}

// pour builtin cd
static int	builtin_cd_utils(char **args)
{
	int	should_free;

	should_free = 0;
	if (args[1] && args[1][0] == '~' && args[1][1] == '/')
		should_free = 1;
	else if (args[1] && args[2] && args[2][0] == '~' && args[2][1] == '/')
		should_free = 1;
	return (should_free);
}

// reproduit la commande cd
int	builtin_cd(char **args, t_pipe *p)
{
	char	*path;
	int		ret;
	int		should_free;

	if (args[1] && args[1][0] == '\0' && !p->var_not_found)
		return (0);
	if (args[1] && ft_strcmp(args[1], "-") == 0)
		return (cd_minus(p));
	if (args[1] && args[2] && ft_strcmp(args[1], "--") != 0)
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	if (args[1] && args[2] && args[3])
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	path = get_cd_path(args, p);
	should_free = builtin_cd_utils(args);
	ret = change_directory(p, path);
	if (should_free && path)
		free(path);
	return (ret);
}
