#include "minishell.h"


// chdir gere tout seul le chemin absolu ou relatif
// return -1 si error
int cd(const char *path, t_shell *env)
{
    struct stat st;

    if (stat(path, &st) != 0)
    {
        perror("stat");
        return (1);
    }
    if (!S_ISDIR(st.st_mode))
    {
        ft_write_error("Not a directory\n");
        return (1);
    }
    if (access(path, X_OK) != 0)
    {
        perror("access");
        return (1);
    }
    if (chdir(path) != 0)
    {
        perror("chdir");
        return (1);
    }
    update_path(env);
    return (0);
}
// pas a faire 
// si path == NULL ou si que des space on renvois dans home (recup home avec **env)