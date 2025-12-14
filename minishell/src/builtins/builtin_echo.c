/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:15:40 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/14 16:18:54 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Vérifie si présence de -n et gère les cas du type -nnnn
static int	flag_n(char *s)
{
	int	i;

	if (!s || s[0] != '-' || s[1] != 'n')
		return (0);
	i = 1;
	while (s[++i])
		if (s[i] != 'n')
			return (0);
	return (1);
}

// print un string
static int	print_clean(char *s)
{
	int		i;
	ssize_t	ret;

	i = 0;
	while (s[i])
	{
		ret = write(1, &s[i], 1);
		if (ret < 0)
			return (-1);
		i++;
	}
	return (0);
}

// return l'index du premier arg (skip les flags)
static int	skip_flag_n(char **args)
{
	int	i;

	i = 1;
	while (args[i] && flag_n(args[i]))
		i++;
	return (i);
}

// reproduit la commande echo
int	builtin_echo(char **args, t_pipe *p)
{
	int	i;
	int	nl;

	(void)p;
	i = skip_flag_n(args);
	nl = (i == 1);
	while (args[i])
	{
		if (print_clean(args[i]) < 0)
			return (0);
		if (args[i + 1])
			if (write(1, " ", 1) < 0)
				return (0);
		i++;
	}
	if (nl)
		write(1, "\n", 1);
	return (0);
}
