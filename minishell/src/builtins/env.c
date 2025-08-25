#include "minishell.h"

void env(t_shell *shell)
{
    int i;
    int j;

    i = 0;
    while (shell->path[i + 1])
    {
        printf("%s\n", shell->path);
        i++;
    }
    j = 0;
    while (shell->var[j])
    {
        printf("%s\n", shell->var[j]);
        j++;
    }
    i++;
    printf("%s\n", shell->path);
}
