size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
    char *s2;

    s2 = (char *)s2
	while (*s2 != c) 
	{
		if (*s2 == '\0')
			return (NULL);
		s2++;
	}
	return (s2);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
    char    *s_start;

    if (!s1 || !s2)
		return (NULL);
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
    s_start = s;
	while (*s1)
        *s++ = *s1++;
	while (*s2)
        *s++ = *s2++;
	*s = '\0';
	return (s_start);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}