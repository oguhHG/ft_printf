/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pintf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:19:05 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/16 15:19:16 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);  // Réutiliser ft_strlen de libft
	write(1, s, len);
	return (len);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);  // Réutiliser ft_itoa de libft
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);  // IMPORTANT: libérer la mémoire allouée par ft_itoa
	return (len);
}