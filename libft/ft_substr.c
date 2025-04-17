
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *result;
    size_t i;

    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
    {
        result = malloc(sizeof(char));
        if (!result)
            return (NULL);
        result[0] = '\0';
        return (result);
    }
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        result[i] = s[start + i];
        i++;
    }
    result[i] = '\0';
    return (result);
}