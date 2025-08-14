#include "minishell.h"
// normalement c bon 
// bien verifier que les quote sont ferme 
// !!! gere le cas echo "oui bonjour ' ok" ||| peut etre chiant a gerer
void echo(char *str)
{
    int i;

    i = 0;
    while (str[i] && ft_iswhitespace(str[i]))
        i++;
    i += 4;
    while (str[i] && ft_iswhitespace(str[i]))
        i++;
    if (str[i] == '-' && str[i + 1] == 'n')
    {
        i += 2;
        echo_loop(str, i, 1);
    }
    else
    {
        echo_loop(str, i, 0);
    }
}

int echo_print_n(char *str, int i)
{
    int j;
    char quote;

    j = 0;
    quote = str[i];
    i++;
    while (str[i + j] && str[i + j] != quote)
        j++;
    printf("%.*s", j, str + i);
    return (i + j + 1);
}

int echo_print(char *str, int i)
{
    int j;

    j = 0;
    while (str[i + j] && !ft_iswhitespace(str[i + j]))
        j++;
    printf("%.*s", j, str + i);
    return (i + j);
}
int is_last_str(char *str, int i)
{
    int j;

    j = 0;
    while (str[i + j] && ft_iswhitespace(str[i + j]))
        j++;
    if (str[i + j] == '\0')
        return (1);
    return (0);
}

// is_n = 1 -> print pas le \n | is_n = 0 -> print \n
void echo_loop(char *str, int i, int is_n)
{
    while (str[i])
        {
            while (str[i] && ft_iswhitespace(str[i]))
                i++;
            if (str[i] == '\'' || str[i] == '\"')
                i = echo_print_n(str, i);
            else
                i = echo_print(str, i);
            if (is_last_str(str, i))
            {
                if (is_n == 1)
                    return ;
                if (is_n == 0)
                    printf("\n");
            }
            else
                printf(" ");
        }
}
