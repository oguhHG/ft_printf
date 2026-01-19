/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 08:14:17 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/19 09:29:55 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char type, va_list args)
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
		return (ft_putptr(va_arg(args, void *)));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_conversion(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/* #include <stdio.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	printf("=== Test %%c ===\n");
	ret1 = ft_printf("ft: %c\n", 'A');
	ret2 = printf("or: %c\n", 'A');
	printf("ret: ft=%d, or=%d\n\n", ret1, ret2);

	printf("=== Test %%s ===\n");
	ret1 = ft_printf("ft: %s\n", "Hello");
	ret2 = printf("or: %s\n", "Hello");
	printf("ret: ft=%d, or=%d\n\n", ret1, ret2);

	printf("=== Test %%d ===\n");
	ret1 = ft_printf("ft: %d\n", -42);
	ret2 = printf("or: %d\n", -42);
	printf("ret: ft=%d, or=%d\n\n", ret1, ret2);

	printf("=== Test %%u ===\n");
	ret1 = ft_printf("ft: %u\n", 4294967295u);
	ret2 = printf("or: %u\n", 4294967295u);
	printf("ret: ft=%d, or=%d\n\n", ret1, ret2);

	printf("=== Test %%x ===\n");
	ret1 = ft_printf("ft: %x\n", 255);
	ret2 = printf("or: %x\n", 255);
	printf("ret: ft=%d, or=%d\n\n", ret1, ret2);

	printf("=== Test %%X ===\n");
	ret1 = ft_printf("ft: %X\n", 255);
	ret2 = printf("or: %X\n", 255);
	printf("ret: ft=%d, or=%d\n\n", ret1, ret2);

	printf("=== Test %%p ===\n");
	ret1 = ft_printf("ft: %p\n", (void *)&ret1);
	ret2 = printf("or: %p\n", (void *)&ret1);
	printf("ret: ft=%d, or=%d\n\n", ret1, ret2);

	printf("=== Test %%%% ===\n");
	ret1 = ft_printf("ft: %%\n");
	ret2 = printf("or: %%\n");
	printf("ret: ft=%d, or=%d\n", ret1, ret2);

	return (0);
} */