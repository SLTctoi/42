/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:13:01 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:13:33 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// crée une copie de l'env
char	**copy_env(char **envp)
{
	int		i;
	char	**env;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

// cherche l'index de var dans envp
int	index_env(char **envp, char *var)
{
	int	i;
	int	len;

	i = 0;
	if (!envp || !var)
		return (-1);
	len = ft_strlen(var);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, len) == 0 && (envp[i][len] == '='
			|| envp[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

// crée une var pour env -> "VAR=VALUE"
static char	*create_var(char *var, char *value)
{
	char	*tmp;
	char	*s;

	if (!value)
		return (ft_strdup(var));
	tmp = ft_strjoin(var, "=");
	s = ft_strjoin(tmp, value);
	free(tmp);
	return (s);
}

// crée une copie de envp en ajoutant var
static char	**copy_env_plus_var(char **envp, char *var)
{
	char	**env;
	int		i;

	i = 0;
	while (envp && envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 2));
	if (!env)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		env[i] = envp[i];
		i++;
	}
	env[i] = var;
	env[i + 1] = NULL;
	return (env);
}

// ajoute var ou met à jour var si elle existe
void	update_var_env(char ***envp, char *var, char *value)
{
	int		i;
	char	*var2;
	char	**env;

	var2 = create_var(var, value);
	i = index_env(*envp, var);
	if (i >= 0)
	{
		free((*envp)[i]);
		(*envp)[i] = var2;
		return ;
	}
	env = copy_env_plus_var(*envp, var2);
	if (!env)
	{
		free(var2);
		return ;
	}
	free(*envp);
	*envp = env;
}
