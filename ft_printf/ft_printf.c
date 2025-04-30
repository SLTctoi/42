/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:24:28 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/29 10:46:34 by mchrispe         ###   ########.fr       */
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

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_format(args, *(++format));
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int		custom_count;
	int		standard_count;
	void	*ptr;

	// Test %c
	custom_count = ft_printf("Custom: %c\n", 'A');
	standard_count = printf("Standard: %c\n", 'A');
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %s
	custom_count = ft_printf("Custom: %s\n", "Hello, world!");
	standard_count = printf("Standard: %s\n", "Hello, world!");
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %p
	ptr = (void *)0x12345678;
	custom_count = ft_printf("Custom: %p\n", ptr);
	standard_count = printf("Standard: %p\n", ptr);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %d
	custom_count = ft_printf("Custom: %d\n", 42);
	standard_count = printf("Standard: %d\n", 42);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %i
	custom_count = ft_printf("Custom: %i\n", -42);
	standard_count = printf("Standard: %i\n", -42);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %u
	custom_count = ft_printf("Custom: %u\n", 4294967295U);
	standard_count = printf("Standard: %u\n", 4294967295U);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %x
	custom_count = ft_printf("Custom: %x\n", 255);
	standard_count = printf("Standard: %x\n", 255);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %X
	custom_count = ft_printf("Custom: %X\n", 255);
	standard_count = printf("Standard: %X\n", 255);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	// Test %%
	custom_count = ft_printf("Custom: %%\n");
	standard_count = printf("Standard: %%\n");
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
		standard_count);
	return (0);
}
*/
#include <stdio.h>

int main() {
    void *ptr = NULL;
    printf("%p\n", ptr);
	ft_printf("%p\n", ptr);
    return 0;
}