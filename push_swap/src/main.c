/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:43:38 by mchrispe          #+#    #+#             */
/*   Updated: 2025/06/30 11:38:46 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_force(t_pile *pile)
{
	if (pile->size_a == 2)
		sort_2(pile);
	else if (pile->size_a == 3)
		sort_3(pile);
	else if (pile->size_a == 4 || pile->size_a == 5)
		sort_4_or_5(pile);
}

int	list_size(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_pile	init_pile(int ac, char **av)
{
	t_list	*lst_a;
	t_pile	pile;

	lst_a = NULL;
	pile.parsing_error = 0;
	if (parsing(ac, av, &lst_a))
		pile.parsing_error = 1;
	pile.lst_a = lst_a;
	pile.size_a = list_size(lst_a);
	pile.lst_b = NULL;
	pile.size_b = 0;
	return (pile);
}

int	main(int ac, char **av)
{
	t_pile	pile;

	if (ac < 2)
		return (1);
	if (verif(av))
		return (error(), 1);
	pile = init_pile(ac, av);
	if (doublon(pile.lst_a) || pile.parsing_error)
		return (free_pile(&pile), error(), 1);
	if (already_sort(pile.lst_a))
		return (free_pile(&pile), 0);
	algo_force(&pile);
	if (already_sort(pile.lst_a))
		return (free_pile(&pile), 0);
	sort_chunk(&pile);
	free_pile(&pile);
	return (0);
}
