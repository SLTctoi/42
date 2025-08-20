#include "minishell.h"

// si ok == 0 si pas ok == 1
int update_path(t_shell *env)
{
    char *cwd;

    cwd = getcwd(NULL, 0);
    if (cwd == NULL)
    {
        perror("getcwd");
        return (1);
    }
    free(env->path);
    env->path = cwd;
    return (0);
}