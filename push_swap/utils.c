int int_log2(int n)
{
    int result = 0;

    while (n > 1)
    {
        n = n / 2;
        result++;
    }
    return (result);
}
int ft_tab_len(int *n)
{
    int i;

    i = 0;
    while (n[i] != -1)
        i++;
    return (i);
}
