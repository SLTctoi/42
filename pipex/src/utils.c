#include "../include/pipex.h"

// charcher la ligne ou y'a PATH (s) -> on return tous ce qu'il y a sur la ligne apres le path
char    *get_path(char *s, char **env)
{
    int i;
    char *path;
    char **all_path;
    char *s_path;

    i = 0;
    all_path = get_all_paths(env);
    if (!all_path && !s) // ?
        return (NULL);
    while (all_path[i])
    {
        path = ft_strjoin(all_path[i], "/");
        s_path = ft_strjoin(path, s);
        free(path);
        if (access(s_path, F_OK) == 0)
        {
            free_split(all_path);
            return (s_path);
        }
        free(s_path);
        i++;
    }
    free_split(all_path);
    return (NULL);
}

char **get_all_paths(char **env)
{
    int i;
    char *path;

    i = 0;
    while (env[i] && ft_strnstr(env[i], "PATH",4) == NULL)
        i++;
    if (!env[i])
        return (NULL);
    path = ft_strchr(env[i], '=');
    if (path != NULL)
        path++;
    return (ft_split(path, ':'));
}

void free_split(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void execute(char *av, char **env)
{
    char *path;
    char **cmd;

    cmd = ft_split(av, ' ');
    path = get_path(cmd[0], env);
    if (!path)
    {
        free_split(cmd);
        error();
    }
    if (execve(path, cmd, env) == -1)
        error();
}

void error(void)
{
    perror("Error");
    exit(1);
}