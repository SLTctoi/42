#include "ft_printf.h"

int	ft_puthex(unsigned int n, int upcase)
{
    int		count;
    char	*base;

    count = 0;
    if (upcase)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    if (n >= 16)
        count += ft_puthex(n / 16, upcase);
    count += ft_putchar(base[n % 16]);
    return (count);
}