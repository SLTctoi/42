#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
    unsigned long	addr;
    int				count;

    addr = (unsigned long)ptr;
    count = ft_putstr("0x");
    count += ft_puthex(addr, 0);
    return (count);
}