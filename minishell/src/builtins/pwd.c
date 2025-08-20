#include "minishell.h"

void pwd(t_shell *env)
{
    printf("%s\n", env->path);
}