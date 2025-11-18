/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_dollar_question.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:14:54 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:15:23 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// affiche le dernier code de sortie
int	builtin_dollar_question(t_pipe *p)
{
	printf("%d\n", p->last_exit);
	return (0);
}
