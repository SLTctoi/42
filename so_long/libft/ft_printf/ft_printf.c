/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:24:28 by mchrispe          #+#    #+#             */
/*   Updated: 2025/05/13 11:45:39 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			count += ft_format(args, *(format));
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

/*
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		custom_count;
	int		standard_count;
	char	*ptr;
	void	*ptr2;
	char	*ptr3;

	// Test %c
	custom_count = ft_printf("%c\n", 'A');
	standard_count = printf("%c\n", 'A');
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %s
	custom_count = ft_printf("%s\n", "Hello, %dworld!42");
	standard_count = printf("%s\n", "Hello, %dworld!42");
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %p
	ptr = "oui";
	custom_count = ft_printf("%p\n", ptr);
	standard_count = printf("%p\n", ptr);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %d
	custom_count = ft_printf("%d\n", 42);
	standard_count = printf("%d\n", 42);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %i
	custom_count = ft_printf("%i\n", -42);
	standard_count = printf("%i\n", -42);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %u
	custom_count = ft_printf("%u\n", 4294967295U);
	standard_count = printf("%u\n", 4294967295U);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %x
	custom_count = ft_printf("%xoui\n", 255);
	standard_count = printf("%xoui\n", 255);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %X
	custom_count = ft_printf("%Xoui\n", 255);
	standard_count = printf("%Xoui\n", 255);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %%
	custom_count = ft_printf("%%probleme?\n");
	standard_count = printf("%%probleme?\n");
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test (nil)
	ptr2 = NULL;
	custom_count = ft_printf("%p\n", ptr2);
	standard_count = printf("%p\n", ptr2);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test multi
	ptr3 = "ok";
	custom_count = ft_printf("%c %s %d %i %u %x %X %p\n", 'A', "Bonjour", 40,
			-42, 429U, 255, 255, ptr3);
	standard_count = printf("%c %s %d %i %u %x %X %p\n", 'A', "Bonjour", 40,
			-42, 429U, 255, 255, ptr3);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	return (0);
}
*/
