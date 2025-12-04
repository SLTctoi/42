/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:17:52 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/04 11:25:24 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// retire les guillemets de s
static char	*strip_all_quotes(const char *s)
{
	int		i;
	int		j;
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
static void	exit_with_error(char *clean, int code, char *arg, t_pipe *p)
{
	if (code == 2)
	{
		write(2, "exit: ", 6);
		write(2, arg, ft_strlen(arg));
		write(2, ": numeric argument required\n", 28);
	}
	else
		write(2, "exit: too many arguments\n", 25);
	free(clean);
	if (code == 2)
	{
		rl_clear_history();
		free_split(p->envp);
		exit(2);
	}
}

// valide et traite l'argument d'exit
static int	process_exit_arg(char **args, t_pipe *p, char **clean_out)
{
	char	*clean;

	if (!args[1])
	{
		rl_clear_history();
		free_split(p->envp);
		exit(p->last_exit);
	}
	clean = strip_all_quotes(args[1]);
	if (!is_numeric(clean))
	{
		p->last_exit = 2;
		exit_with_error(clean, 2, args[1], p);
	}
	if (args[2])
	{
		p->last_exit = 1;
		exit_with_error(clean, 1, args[1], p);
		return (0);
	}
	*clean_out = clean;
	return (1);
}

// reproduit la commande exit
int	builtin_exit(char **args, t_pipe *p)
{
	long	code;
	char	*clean;

	if (isatty(STDIN_FILENO))
		ft_putendl_fd("exit", 1);
	if (!process_exit_arg(args, p, &clean))
		return (1);
	code = ft_atoi(clean);
	free(clean);
	rl_clear_history();
	free_split(p->envp);
	exit(code % 256);
}
