void bzero(void *s, size_t n)
{
    int i;

    i = n;
    while (i != '/0')
    {
        s[i] = '/0';
        i++;
    }
}