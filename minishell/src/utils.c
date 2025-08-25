#include "minishell.h"

void    ft_write_error(const char *err)
{
    write(2, err, ft_strlen(err));
}

void    sort_lst(char **lst)
{
    int i;
    int j;
    int count;
    char *temp;

    i = 0;
    count = 0;
    while (lst[count])
        count++;
    while (i < count)
    {
        j = 0;
        while (j < (count - i - 1))
        {
            if (ft_strcmp(lst[j], lst[j + 1]) > 0)
            {
                temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
char **copy_string_array(char **lst)
{
    char **copy;
    int count;
    int i;
    int j;

    i = 0;
    count = ft_strarray_len(lst);
    copy = malloc(sizeof(char *) * (count + 1));
    if (!copy)
        return (NULL);
    while (i < count)
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
    copy[count] = NULL;
    return (copy); 
}

int ft_strarray_len(char **lst)
{
    int count;

    count = 0;
    while (lst[count])
        count++;
    return (count);
}
