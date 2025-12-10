/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:17:52 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 18:38:24 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// convertit en long et détecte l'overflow (retourne 0 si overflow)
static int	safe_atol(const char *s, long *out)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > 922337203685477580L)
			return (0);
		if (result == 922337203685477580L && s[i] > '7')
			if (!(sign == -1 && s[i] == '8' && !s[i + 1]))
				return (0);
		result = result * 10 + (s[i] - '0');
		i++;
	}
	*out = result * sign;
	return (1);
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
	cleanup_minishell_resources(p);
	if (code == 2)
		exit(2);
	exit(1);
}

// valide et traite l'argument d'exit
static int	process_exit_arg(char **args, t_pipe *p, char **clean_out)
{
	char	*clean;

	if (!args[1])
	{
		cleanup_minishell_resources(p);
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
	if (!safe_atol(clean, &code))
	{
		p->last_exit = 2;
		exit_with_error(clean, 2, args[1], p);
	}
	free(clean);
	cleanup_minishell_resources(p);
	exit(code % 256);
}
