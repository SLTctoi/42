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

static int	ft_puthex_ptr(unsigned long n, int upcase)
{
	int		count;
	char	*base;

	count = 0;
	if (upcase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_ptr(n / 16, upcase);
	count += ft_putchar(base[n % 16]);
	return (count);
}

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
		count += ft_puthex_ptr(addr, 0);
	}
	return (count);
}
