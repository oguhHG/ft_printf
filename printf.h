#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* Main function */
int		ft_printf(const char *format, ...);

/* Conversion handlers */
int		handle_conversion(char type, va_list args);

/* Output functions */
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex_lower(unsigned int n);
int		ft_puthex_upper(unsigned int n);
int		ft_putptr(unsigned long ptr);

/* Helper functions */
int		ft_puthex_ptr(unsigned long n);

#endif