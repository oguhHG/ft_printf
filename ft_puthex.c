/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 08:14:17 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/19 08:58:48 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int n)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex_lower(n / 16);
	len += write(1, &hex[n % 16], 1);
	return (len);
}

int	ft_puthex_upper(unsigned int n)
{
	int		len;
	char	*hex;

	hex = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_puthex_upper(n / 16);
	len += write(1, &hex[n % 16], 1);
	return (len);
}

static int	ft_puthex_ptr(unsigned long n)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex_ptr(n / 16);
	len += write(1, &hex[n % 16], 1);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	addr;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	len = write(1, "0x", 2);
	len += ft_puthex_ptr(addr);
	return (len);
}
