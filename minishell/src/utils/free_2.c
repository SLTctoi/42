/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:09:16 by mchrispe          #+#    #+#             */
/*   Updated: 2025/12/09 19:09:28 by mchrispe         ###   ########.fr       */
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