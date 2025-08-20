#include "minishell.h"

char **copy_str_array_without_last(char **lst)
{
    char **copy;
    int count;
    int i;
    int j;

    count = ft_strarray_len(lst);
    copy = malloc(sizeof(char *) * count);
    if (!copy)
        return (NULL);
    i = 0;
    while (i < count - 1)
    {
        copy[i] = ft_strdup(lst[i]);
        if (!copy[i])
        {
            j = -1;
            while (++j < i)
                free(copy[j]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[count - 1] = NULL;
    return (copy);
}
