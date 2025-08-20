#include "minishell.h"

void free_shell(t_shell *shell)
{
    (void)shell;
}

void free_string_array(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
void free_exit(int i)
{
    // condition avec free partout
    // free var
    exit(i);
}