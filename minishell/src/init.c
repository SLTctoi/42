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

// init dup(STDIN) et STDOUT
int init_minishell(t_minishell *minishell)
{
    minishell->in = dup(STDIN_FILENO);
    if (minishell->in == -1)
    {
        perror("dup");
        return (-1);
    }
    minishell->out = dup(STDOUT_FILENO);
    if (minishell->out == -1)
    {
        perror("dup");
        return (-1);
    }
    return (0);
}