/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:09:16 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/10 11:10:19 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_child_resources(t_pipe *p)
{
	if (p->envp)
	{
		free_split(p->envp);
		p->envp = NULL;
	}
	rl_clear_history();
}
