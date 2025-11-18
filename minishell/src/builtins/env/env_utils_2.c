/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:11:30 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:11:31 by mchrispe         ###   ########.fr       */
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
