#include <stdio.h>
#include <stdarg.h>

int printf(const char *format,int a );

int	handle_conversion(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (type == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (type == 'x')
		return (ft_puthex_lower(va_arg(args, unsigned int)));
	if (type == 'X')
		return (ft_puthex_upper(va_arg(args, unsigned int)));
	if (type == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}