#include "minishell.h"

// remplace les occurrences de "$?" par le dernier code de sortie
void replace_dollar_question(char **argv, t_pipe *p)
{
    int i;
    char *tmp;

    i = 0;
    while (argv[i])
    {
        if (ft_strcmp(argv[i], "$?") == 0)
        {
            tmp = ft_itoa(p->last_exit);
            free(argv[i]);
            argv[i] = tmp;
        }
        i++;
    }
}


