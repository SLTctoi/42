/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:28:44 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/28 11:28:56 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (ptr == NULL)
		count = ft_putstr("(nil)");
	else
	{
		addr = (unsigned long)ptr;
		count = ft_putstr("0x");
		count += ft_puthex(addr, 0);
	}
	return (count);
}
