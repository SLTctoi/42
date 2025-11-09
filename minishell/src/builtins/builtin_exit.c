#include "minishell.h"

// retire les guillemets de s
static char	*strip_all_quotes(const char *s)
{
	int	i;
	int	j;
	char	*res;

	if (!s)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\'' && s[i] != '"')
			res[j++] = s[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

// vérifie si s et un nombre entier (+/- marche)
static int	is_numeric(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
// gère les erreurs d'exit
static void	exit_with_error(char *clean, int code)
{
	if (code == 2)
		write(2, " numeric argument required\n", 27);
	else
		write(2, "exit: too many arguments\n", 25);
	free(clean);
	if (code == 2)
		exit(2);
}

// reproduit la commande exit
int	builtin_exit(char **args, t_pipe *p)
{
	long	code;
	char	*clean;

	ft_putendl_fd("exit", 1);
	if (!args[1])
		exit(p->last_exit);
	clean = strip_all_quotes(args[1]);
	if (!is_numeric(clean))
	{
		p->last_exit = 2;
		exit_with_error(clean, 2);
	}
	if (args[2])
	{
		p->last_exit = 1;
		exit_with_error(clean, 1);
		return (1);
	}
	code = ft_atoi(clean);
	free(clean);
	exit(code % 256);
}
