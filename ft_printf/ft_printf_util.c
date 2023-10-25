/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:49:31 by man               #+#    #+#             */
/*   Updated: 2023/04/15 16:21:59 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putchar('-', count);
		ft_putchar('2', count);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	ft_putchar(n % 10 + '0', count);
}

void	ft_putnbr_rev(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putnbr_rev(n / 10, count);
	ft_putchar(n % 10 + '0', count);
}

void	ft_get_hex(char c, unsigned long long nb, int *count)
{
	char	*base;

	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_get_hex(c, nb / 16, count);
		ft_get_hex(c, nb % 16, count);
	}
	else
	{
		ft_putchar(base[nb], count);
	}
}
