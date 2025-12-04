/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_rebuild.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:00:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/04 17:43:10 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// compte le nombre total d'args apres word splitting
int	count_total_args(char **argv, char **envp, int last_exit, t_pipe *p)
{
	char	**split;
	char	*exp;
	int		i;
	int		total;

	total = 0;
	i = -1;
	while (argv[++i])
	{
		exp = parse_and_expand(argv[i], envp, last_exit, p);
		if (exp && has_unquoted_variable(argv[i]))
		{
			split = split_on_whitespace(exp);
			if (split)
			{
				total += count_split_args(split);
				free_split(split);
			}
		}
		else
			total++;
		free(exp);
	}
	return (total);
}

// remplit new_argv avec les args splites
void	fill_new_argv(char **new_argv, char **argv, char **envp,
		t_exp_params prm)
{
	char	**split;
	char	*exp;
	int		i;
	int		k;

	k = 0;
	i = -1;
	while (argv[++i])
	{
		exp = parse_and_expand(argv[i], envp, prm.last_exit, prm.p);
		if (exp && has_unquoted_variable(argv[i]))
		{
			split = split_on_whitespace(exp);
			if (split)
				k = copy_split_to_argv(new_argv, split, k);
			free(exp);
		}
		else if (exp)
			new_argv[k++] = exp;
	}
	new_argv[k] = NULL;
}

// reconstruit argv en appliquant word splitting si necessaire
char	**rebuild_argv_with_splitting(char **argv, char **envp,
		int last_exit, t_pipe *p)
{
	char			**new_argv;
	int				total;
	t_exp_params	prm;

	total = count_total_args(argv, envp, last_exit, p);
	new_argv = malloc(sizeof(char *) * (total + 1));
	if (!new_argv)
		return (NULL);
	prm.last_exit = last_exit;
	prm.p = p;
	fill_new_argv(new_argv, argv, envp, prm);
	return (new_argv);
}

// parse_and_expand pour tous les argv
void	expand_vars_new(char **argv, char **envp, int last_exit, t_pipe *p)
{
	char	**new_argv;
	int		i;

	new_argv = rebuild_argv_with_splitting(argv, envp, last_exit, p);
	if (!new_argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	i = 0;
	while (new_argv[i])
	{
		argv[i] = new_argv[i];
		i++;
	}
	argv[i] = NULL;
	free(new_argv);
}
