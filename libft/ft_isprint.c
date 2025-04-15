int	ft_isprint(int c)
{
	if ((c >= 7 && c <= 13) || (c >= 32 && c <= 126))
		return (1);
	return (0);
}