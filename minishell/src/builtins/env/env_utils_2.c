/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:11:30 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:21:24 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// calcule la taille de l'env
int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

// swap 2 pointeurs
static void	swap_env(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// crée une copie triée de l'env
char	**sorted_env(char **env)
{
	char	**copy;
	int		size;
	int		i;
	int		j;

	size = size_env(env);
	copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < size)
		copy[i] = ft_strdup(env[i]);
	copy[size] = NULL;
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			if (ft_strcmp(copy[j], copy[j + 1]) > 0)
				swap_env(&copy[j], &copy[j + 1]);
	}
	return (copy);
}

// filtre l'env pour ne garder que les var avec = (pour execve)
char	**filter_env_for_exec(char **envp)
{
	int		i;
	int		j;
	int		count;
	char	**env;

	i = -1;
	count = 0;
	while (envp && envp[++i])
	{
		if (ft_strchr(envp[i], '='))
			count++;
	}
	env = malloc(sizeof(char *) * (count + 1));
	if (!env)
		return (NULL);
	i = 0;
	j = 0;
	while (envp && envp[i])
	{
		if (ft_strchr(envp[i], '='))
			env[j++] = envp[i];
		i++;
	}
	env[j] = NULL;
	return (env);
}
