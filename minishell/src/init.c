#include "minishell.h"

// si ok == 0 si pas ok == 1
int init_path(t_shell *env)
{
    env->path = getcwd(NULL, 0);
    if (env->path == NULL)
    {
        perror("getcwd");
        return (0);
    }
    return (1);
}