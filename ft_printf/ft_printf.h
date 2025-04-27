#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex(unsigned int n, int upcase);

int ft_printf(const char *format, ...);
int ft_format(va_list args, char c);

#endif
