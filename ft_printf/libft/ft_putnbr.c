#include "ft_printf.h"

int	ft_putnbr(int n)
{
    int		count;

    count = 0;
    if (n == -2147483648)
    {
        count += ft_putchar('-');
        count += ft_putchar('2');
        n = 147483648;
    }
    if (n < 0)
    {
        count += ft_putchar('-');
        n = -n;
    }
    count += ft_putnbr_unsigned((unsigned int)n);
    return (count);
}