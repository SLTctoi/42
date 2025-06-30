/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:50:37 by mchrispe          #+#    #+#             */
/*   Updated: 2025/06/30 10:50:38 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_a(t_pile *pile)
{
	t_list	*tmp;

	if (!pile->lst_b)
		return ;
	tmp = pile->lst_b;
	pile->lst_b = tmp->next;
	tmp->next = pile->lst_a;
	pile->lst_a = tmp;
	pile->size_b--;
	pile->size_a++;
	write(1, "pa\n", 3);
}

void	push_b(t_pile *pile)
{
	t_list	*tmp;

	if (!pile->lst_a)
		return ;
	tmp = pile->lst_a;
	pile->lst_a = tmp->next;
	tmp->next = pile->lst_b;
	pile->lst_b = tmp;
	pile->size_a--;
	pile->size_b++;
	write(1, "pb\n", 3);
}
