#include "minishell.h"

// Retire les guillemets englobants d'une chaîne
char *strip_wrapping_quotes(const char *s)
{
    size_t len;
    size_t i;
    char *res;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    if (len >= 2 && ((s[0] == '"' && s[len - 1] == '"') ||
                     (s[0] == '\'' && s[len - 1] == '\'')))
    {
        res = malloc(len - 1);
        if (!res)
            return (NULL);
        i = 0;
        while (i < len - 2)
        {
            res[i] = s[i + 1];
            i++;
        }
        res[i] = '\0';
        return (res);
    }
    return (ft_strdup(s));
}
