int ft_intlen(int n)
{
    int len;

    // reverif
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

char *ft_itoa(int n)
{
    int len = ft_intlen(n);
    char *s1;
    long nb = n;

    s1 = malloc(sizeof(char) * (len + 1));
    if (!s1)
        return NULL;
    s1[len] = '\0';
    if (nb < 0)
    {
        s1[0] = '-';
        nb = -nb;
    }
    if (nb == 0)
        s1[0] = '0';
    while (nb > 0)
    {
        s1[--len] = (nb % 10) + '0';
        nb /= 10;
    }
    return s1;
}
