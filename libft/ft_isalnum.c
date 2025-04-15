int	ft_alnum(int c)
{
	if ((c >= 0 && c <= 9) || (c >= 'a' && c <= 'z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}