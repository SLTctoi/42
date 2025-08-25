#include "minishell.h"

int	ft_is_delim(char ch, const char *delims)
{
	while (*delims)
	{
		if (ch == *delims)
			return (1);
		delims++;
	}
	return (0);
}

int	ft_word_count(const char *s, const char *delims)
{
	int		count;
	int		in_word;
	char	quote;

	count = 0;
	in_word = 0;
	quote = 0;
	while (*s)
	{
		if (!quote && (*s == '"' || *s == '\''))
			quote = *s;
		else if (quote && *s == quote)
			quote = 0;
		if (!ft_is_delim(*s, delims) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if ((ft_is_delim(*s, delims) && !quote) || (!*s))
			in_word = 0;

		s++;
	}
	return (count);
}

char	*ft_strndup(const char *s, int len)
{
	char	*str;
	int		i;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_free_all(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

const char	*ft_advance_delim(const char *s, const char *delims)
{
	while (*s && ft_is_delim(*s, delims))
		s++;
	return (s);
}