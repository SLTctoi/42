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
	custom_count = ft_printf("%s\n", "Hello, world!");
	standard_count = printf("%s\n", "Hello, world!");
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
	custom_count = ft_printf("%x\n", 255);
	standard_count = printf("%x\n", 255);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %X
	custom_count = ft_printf("%X\n", 255);
	standard_count = printf("%X\n", 255);
	printf("Custom count: %d | Standard count: %d\n\n", custom_count,
			standard_count);
	// Test %%
	custom_count = ft_printf("%%\n");
	standard_count = printf("%%\n");
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