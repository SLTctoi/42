/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:49:50 by mchrispe          #+#    #+#             */
/*   Updated: 2025/06/30 10:50:17 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_list *lst)
{
	int		min;
	int		i;
	int		index;
	t_list	*tmp;

	i = 0;
	index = 0;
	tmp = lst;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	push_min_to_b(t_pile *pile)
{
	int	index;

	index = find_min(pile->lst_a);
	if (index == 1)
		rotate_a(pile);
	else if (index == 2)
	{
		rotate_a(pile);
		rotate_a(pile);
	}
	else if (index == 3)
	{
		rrotate_a(pile);
		rrotate_a(pile);
	}
	else if (index == 4)
		rrotate_a(pile);
	push_b(pile);
}

void	sort_2(t_pile *pile)
{
	swap_a(pile);
}

void	sort_3(t_pile *pile)
{
	int	i;
	int	j;
	int	k;

	i = pile->lst_a->content;
	j = pile->lst_a->next->content;
	k = pile->lst_a->next->next->content;
	if (i > j && j < k && i < k)
		swap_a(pile);
	else if (i > j && j > k)
	{
		swap_a(pile);
		rrotate_a(pile);
	}
	else if (i > j && j < k && i > k)
		rotate_a(pile);
	else if (i < j && j > k && i < k)
	{
		swap_a(pile);
		rotate_a(pile);
	}
	else if (i < j && j > k && i > k)
		rrotate_a(pile);
}

void	sort_4_or_5(t_pile *pile)
{
	if (pile->size_a == 5)
		push_min_to_b(pile);
	push_min_to_b(pile);
	sort_3(pile);
	while (pile->size_b > 0)
		push_a(pile);
}
