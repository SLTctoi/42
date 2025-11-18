/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_question.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:21:46 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:21:55 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// remplace les occurrences de "$?" par le dernier code de sortie
void	replace_dollar_question(char **argv, t_pipe *p)
{
	int		i;
	char	*tmp;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "$?") == 0)
		{
			tmp = ft_itoa(p->last_exit);
			free(argv[i]);
			argv[i] = tmp;
		}
		i++;
	}
}
