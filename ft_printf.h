/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 08:14:17 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/19 08:58:54 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex_lower(unsigned int n);
int	ft_puthex_upper(unsigned int n);
int	ft_putptr(void *ptr);

#endif