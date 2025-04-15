char    *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int j;
    int k;
    int inset;
    char *s2;

    if (!(s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
        return (NULL);
    i = 0;
    k = 0;
    while (s1[i] != '\0')
    {
        inset = 0;
        j = 0;
        while (set[j] != '\0')
        {
            if (s1[i] = set[j])
                inset = 1;
            j++;
        }
        if (!inset)
        {
            s2[k] = s1[i]
            k++;
        }
        i++;
    }
    s2[k] = '\0';
    return (s2);
}