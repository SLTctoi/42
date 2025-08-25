#include "minishell.h"

int	var_name_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != '=' && s2[i] && s2[i] != '=' && s1[i] == s2[i])
		i++;
	if ((s1[i] == '=' || s1[i] == '\0') && (s2[i] == '=' || s2[i] == '\0'))
		return (0);
	return (s1[i] - s2[i]);
}

int	is_in_str_array(char **array, char *str)
{
	int	i;

	if (!array || !str)
		return (0);
	i = 0;
	while (array[i])
	{
		if (var_name_cmp(array[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	**add_to_str_array(char **array, char *str)
{
	int		len;
	int		i;
	char	**new_array;

	len = 0;
	while (array && array[len])
		len++;
	new_array = malloc(sizeof(char *) * (len + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i++] = ft_strdup(str);
	new_array[i] = NULL;
	free_string_array(array);
	return (new_array);
}

void	replace_or_add(char ***env, char *str)
{
	int	i;

	if (!env || !*env)
	{
		*env = add_to_str_array(NULL, str);
		return ;
	}
	i = 0;
	while ((*env)[i])
	{
		if (var_name_cmp((*env)[i], str) == 0)
		{
			free((*env)[i]);
			(*env)[i] = ft_strdup(str);
			return ;
		}
		i++;
	}
	*env = add_to_str_array(*env, str);
}
