#include "minishell.h"


// chdir gere tout seul le chemin absolu ou relatif
// return -1 si error
int cd(const char *path)
{
    struct stat st;

    if (stat(path, &st) != 0)
    {
        perror("Error: invalid path");
        return (-1);
    }
    if (!S_ISDIR(st.st_mode))
    {
        ft_write_error("Error: it's not a dir\n");
        return (-1);
    }
    if (acces(path, R_OK | X_OK) != 0)
    {
        perror("Error: permission denied");
        return (-1);
    }
    if (chdir(path) != 0)
    {
        perror("Error: chdir");
        return (-1);
    }
    return (0);
}
