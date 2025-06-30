/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:45:22 by mchrispe          #+#    #+#             */
/*   Updated: 2025/06/30 10:45:24 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	simple_sort(int *lst, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (lst[i] > lst[j])
			{
				tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sort_tab(t_list *lst, int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size && lst)
	{
		tab[i] = lst->content;
		lst = lst->next;
		i++;
	}
	simple_sort(tab, size);
	return (tab);
}

void	replace_by_index(t_pile *pile)
{
	t_list	*tmp;
	int		*lst;
	int		i;

	lst = sort_tab(pile->lst_a, pile->size_a);
	if (!lst)
		return ;
	tmp = pile->lst_a;
	while (tmp)
	{
		i = 0;
		while (i < pile->size_a)
		{
			if (tmp->content == lst[i])
			{
				tmp->content = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(lst);
}

int	get_max_index(t_list *lst)
{
	int	i;
	int	index;
	int	max;

	if (!lst)
		return (-1);
	i = 1;
	index = 0;
	max = lst->content;
	lst = lst->next;
	while (lst)
	{
		if (lst->content > max)
		{
			max = lst->content;
			index = i;
		}
		lst = lst->next;
		i++;
	}
	return (index);
}

void	push_b_sort(t_pile *pile)
{
	int	i;

	while (pile->size_b > 0)
	{
		i = get_max_index(pile->lst_b);
		if (i <= pile->size_b / 2)
		{
			while (i-- > 0)
				rotate_b(pile);
		}
		else
		{
			while (i++ < pile->size_b)
				rrotate_b(pile);
		}
		push_a(pile);
	}
}
