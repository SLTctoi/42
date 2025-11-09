#include "minishell.h"

// Extrait les chemins depuis la variable PATH de l'environnement
static char **get_paths_from_env(char **envp)
{
    int i;
    char *path_line;

    if (!envp)
        return (NULL);
    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path_line = envp[i] + 5;
            return (ft_split(path_line, ':'));
        }
        i++;
    }    
    return (NULL);
}

// Concatène un répertoire et un nom de commande avec '/' entre les deux
static char *join_path_cmd(char *dir, char *cmd)
{
    char *tmp;
    char *full;

    if (!dir || !cmd)
        return (NULL);
    tmp = ft_strjoin(dir, "/");
    if (!tmp)
        return (NULL);
    full = ft_strjoin(tmp, cmd);
    free(tmp);
    return (full);
}

// Vérifie si la commande est un chemin absolu exécutable
static char	*check_absolute_path(char *cmd)
{
	struct stat	st;

	if (stat(cmd, &st) == 0 && S_ISDIR(st.st_mode))
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

// Cherche la commande dans les répertoires du PATH
static char	*search_in_paths(char **paths, char *cmd)
{
	char		*path;
	int			i;
	struct stat	st;

	i = -1;
	while (paths[++i])
	{
		path = join_path_cmd(paths[i], cmd);
		if (path && stat(path, &st) == 0 && S_ISDIR(st.st_mode))
		{
			free(path);
			continue ;
		}
		if (path && access(path, X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

// Cherche une commande dans le PATH ou vérifie un chemin absolu
char	*find_cmd(char *cmd, char **envp)
{
	char	**paths;
	char	*result;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (check_absolute_path(cmd));
	paths = get_paths_from_env(envp);
	if (!paths)
		return (NULL);
	result = search_in_paths(paths, cmd);
	free_split(paths);
	return (result);
}
