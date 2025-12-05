/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:05:08 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/05 13:09:56 by mchrispe         ###   ########.fr       */
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

// Obtient le chemin du répertoire home
static char	*get_home_dir(t_pipe *p)
{
	int		idx;
	char	*home;

	idx = index_env(p->envp, "HOME");
	if (idx >= 0)
	{
		home = ft_strchr(p->envp[idx], '=') + 1;
		if (home && *home)
			return (home);
	}
	return ("/home/mchrispe");
}

// change le répertoire courant et met à jour PWD et OLDPWD
int	change_directory(t_pipe *p, char *path)
{
	char	*oldpwd;
	char	*newpwd;

	oldpwd = getcwd(NULL, 0);
	if (!path)
		path = get_home_dir(p);
	if (!path)
		return (write(2, "cd: HOME not set\n", 17), free(oldpwd), 1);
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

// Expand le tilde (~) dans le chemin
static char	*expand_tilde(char *path, t_pipe *p)
{
	char	*home;
	char	*result;

	if (!path || path[0] != '~')
		return (path);
	home = get_home_dir(p);
	if (path[1] == '\0')
		return (home);
	if (path[1] == '/')
	{
		result = ft_strjoin(home, path + 1);
		return (result);
	}
	return (path);
}

// Détermine le chemin pour la commande cd. Gère les cas spéciaux vide - --
// cd vide -> HOME | cd -- -ok
char	*get_cd_path(char **args, t_pipe *p)
{
	int		idx;
	char	*path;

	if (!args[1] || (args[1] && args[1][0] == '\0' && p->var_not_found))
		return (NULL);
	if (ft_strcmp(args[1], "--") == 0)
	{
		if (args[2])
			return (expand_tilde(args[2], p));
		return (NULL);
	}
	if (ft_strcmp(args[1], "-") == 0)
	{
		idx = index_env(p->envp, "OLDPWD");
		if (idx >= 0)
			return (ft_strchr(p->envp[idx], '=') + 1);
		return (NULL);
	}
	path = expand_tilde(args[1], p);
	return (path);
}
