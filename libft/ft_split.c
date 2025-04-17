size_t	count_words(const char *s, char c)
{
    size_t	count = 0;
    int		in_word = 0;

    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

char	*word_dup(const char *s, size_t start, size_t end)
{
    char	*word;
    size_t	i;

    word = ft_calloc(end - start + 1, sizeof(char));
    if (!word)
        return (NULL);
    i = 0;
    while (start < end)
        word[i++] = s[start++];
    return (word);
}

char	**ft_split(char const *s, char c)
{
    char	**result;
    size_t	i;
    size_t	j;
    size_t	start;

    i = 0;
    j = 0;
    start = 0;
    if (!s)
        return (NULL);
    result = ft_calloc(count_words(s, c) + 1, sizeof(char *));
    if (!result)
        return (NULL);
    while (s[i])
    {
        if (s[i] != c)
        {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            result[j++] = word_dup(s, start, i);
            if (!result[j - 1])
            {
                while (j > 0)
                    free(result[--j]);
                free(result);
                return (NULL);
            }
        }
        else
            i++;
    }
    return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
    char **result;
    size_t i;

    result = ft_split("Hello world 42", ' ');
    for (i = 0; result[i]; i++)
        printf("Custom: %s\n", result[i]);
    for (i = 0; result[i]; i++)
        free(result[i]);
    free(result);

    result = ft_split(",,,42,,,cursus,,,", ',');
    for (i = 0; result[i]; i++)
        printf("Custom: %s\n", result[i]);
    for (i = 0; result[i]; i++)
        free(result[i]);
    free(result);

    result = ft_split("", ',');
    for (i = 0; result[i]; i++)
        printf("Custom: %s\n", result[i]);
    for (i = 0; result[i]; i++)
        free(result[i]);
    free(result);

    result = ft_split("42", ' ');
    for (i = 0; result[i]; i++)
        printf("Custom: %s\n", result[i]);
    for (i = 0; result[i]; i++)
        free(result[i]);
    free(result);

    return (0);
}
*/