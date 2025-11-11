#include "minishell.h"

// Verifie si var existe dans env
static int	ft_strncmp_env(char *env_entry, char *var, int len)
{
	return (ft_strncmp(env_entry, var, len) == 0 &&
	        (env_entry[len] == '=' || env_entry[len] == '\0'));
}

// Libère partiellement un env en cas d'erreur
static void	free_partial_env(char **env, int j)
{
	while (j--)
		free(env[j]);
	free(env);
}

// Libère un tableau d'environnement
void	free_env(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return ;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

// crée une copie de env sans var
static char	**rm_var_from_env(char **envp, char *var, int len)
{
	char	**env;
	int		i;
	int		j;

	if (!(env = malloc(sizeof(char *) * (size_env(envp) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (!ft_strncmp_env(envp[i], var, len))
		{
			env[j] = ft_strdup(envp[i]);
			if (!env[j])
			{
				free_partial_env(env, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	env[j] = NULL;
	return (env);
}

// Supprime une var d'env
void	remove_env(char ***envp, char *var)
{
	char	**env;
	int		len;

	if (!*envp || !var)
		return ;
	len = ft_strlen(var);
	env = rm_var_from_env(*envp, var, len);
	if (!env)
		return ;
	free_env(*envp);
	*envp = env;
}

