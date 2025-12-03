/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:05:08 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/03 23:03:04 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// met à jour PWD et OLDPWD dans l'environnement
static void	update_pwd_vars(t_pipe *p, char *oldpwd, char *newpwd)
{
	if (oldpwd)
		update_var_env(&p->envp, "OLDPWD", oldpwd);
	if (newpwd)
		update_var_env(&p->envp, "PWD", newpwd);
	free(oldpwd);
	free(newpwd);
}

// change le répertoire courant et met à jour PWD et OLDPWD
static int	change_directory(t_pipe *p, char *path)
{
	char	*oldpwd;
	char	*newpwd;
	int		idx;

	oldpwd = getcwd(NULL, 0);
	if (!path)
	{
		idx = index_env(p->envp, "HOME");
		if (idx >= 0)
			path = ft_strchr(p->envp[idx], '=') + 1;
	}
	if (!path)
		return (write(2, "cd: HOME or OLDPWD not set\n", 27), free(oldpwd), 1);
	if (chdir(path) != 0)
	{
		write(2, "cd: ", 4);
		write(2, path, ft_strlen(path));
		write(2, ": No such file or directory\n", 29);
		return (free(oldpwd), 1);
	}
	newpwd = getcwd(NULL, 0);
	update_pwd_vars(p, oldpwd, newpwd);
	return (0);
}

// Détermine le chemin pour la commande cd. Gère les cas spéciaux vide - --
// cd vide -> HOME | cd -- -ok
static char	*get_cd_path(char **args, t_pipe *p)
{
	int	idx;

	if (!args[1] || (args[1] && args[1][0] == '\0' && p->var_not_found))
		return (NULL);
	if (ft_strcmp(args[1], "--") == 0)
	{
		if (args[2])
			return (args[2]);
		return (NULL);
	}
	if (ft_strcmp(args[1], "-") == 0)
	{
		idx = index_env(p->envp, "OLDPWD");
		if (idx >= 0)
			return (ft_strchr(p->envp[idx], '=') + 1);
		return (NULL);
	}
	return (args[1]);
}

// Gère le cas "cd -" -> change de répertoire pour aller dans OLDPWD
static int	cd_minus(t_pipe *p)
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

// reproduit la commande cd
int	builtin_cd(char **args, t_pipe *p)
{
	char	*path;

	if (args[1] && args[1][0] == '\0' && !p->var_not_found)
		return (0);
	if (args[1] && args[2])
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	if (args[1] && ft_strcmp(args[1], "-") == 0)
		return (cd_minus(p));
	path = get_cd_path(args, p);
	return (change_directory(p, path));
}
