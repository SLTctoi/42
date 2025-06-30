/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:37:24 by mchrispe          #+#    #+#             */
/*   Updated: 2025/06/30 11:04:00 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parsing(int ac, char **av, t_list **lst_a)
{
	int		i;
	int		j;
	char	**s;

	i = 1;
	while (i < ac)
	{
		s = ft_split(av[i], ' ');
		j = 0;
		while (s[j])
		{
			if (!max_min(s[j]))
			{
				free_split(s);
				return (1);
			}
			ft_lstadd_back(lst_a, lstnew(ft_atoi(s[j])));
			j++;
		}
		free_split(s);
		i++;
	}
	return (0);
}

int	max_min(char *s)
{
	int		sign;
	long	result;
	int		digit;

	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (*s == '+')
		s++;
	result = 0;
	while (*s)
	{
		digit = *s - '0';
		if (sign == 1 && result > (2147483647 - digit) / 10)
			return (0);
		if (sign == -1 && - result < (-2147483648 + digit) / 10)
			return (0);
		result = result * 10 + digit;
		s++;
	}
	result *= sign;
	return (result >= -2147483648 && result <= 2147483647);
}

int	verif(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == ' ')
				j++;
			if (s[i][j] == '+' || s[i][j] == '-')
			{
				if ((j > 0 && s[i][j - 1] != ' ') || !ft_isdigit(s[i][j + 1]))
					return (1);
				j++;
			}
			while (ft_isdigit(s[i][j]))
				j++;
			if (s[i][j] && s[i][j] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	doublon(t_list *lst)
{
	t_list	*current;
	t_list	*check;

	current = lst;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->content == check->content)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	already_sort(t_list *lst)
{
	t_list	*current;
	t_list	*nxt;

	current = lst;
	while (current)
	{
		nxt = current->next;
		while (nxt)
		{
			if (current->content >= nxt->content)
				return (0);
			nxt = nxt->next;
		}
		current = current->next;
	}
	return (1);
}
