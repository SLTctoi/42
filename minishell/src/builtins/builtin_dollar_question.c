#include "minishell.h"

// affiche le dernier code de sortie
int builtin_dollar_question(t_pipe *p)
{
    printf("%d\n", p->last_exit);
    return (0);
}