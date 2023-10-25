/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:22:47 by man               #+#    #+#             */
/*   Updated: 2023/04/20 17:00:50 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, va_list list, int *count)
{
	char	tmp;
	char	*str;

	if (c == 'c')
	{
		tmp = va_arg(list, int);
		ft_putchar(tmp, count);
	}
	else
	{
		str = va_arg(list, char *);
		if (!str)
		{
			write(1, "(null)", 6);
			(*count) += 6;
			return ;
		}
		while (*str)
		{
			ft_putchar((*str), count);
			str++;
		}
	}
}

void	print_int(char c, va_list list, int *count)
{
	int				nbr;
	unsigned int	rev_nbr;

	nbr = va_arg(list, int);
	if (c == 'd' || c == 'i')
		ft_putnbr(nbr, count);
	else
	{
		rev_nbr = (unsigned int)nbr;
		ft_putnbr_rev(rev_nbr, count);
	}
}

void	print_hex(char c, va_list list, int *count)
{
	void	*tmp;

	if (c == 'x' || c == 'X')
		ft_get_hex(c, va_arg(list, unsigned int), count);
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		tmp = va_arg(list, void *);
		ft_get_hex(c, (unsigned long long)tmp, count);
	}
}

void	check(char c, va_list list, int *count)
{
	if (c == 'd' || c == 'i' || c == 'u')
		print_int(c, list, count);
	else if (c == 'c' || c == 's')
		print_char(c, list, count);
	else if (c == 'p' || c == 'x' || c == 'X')
		print_hex(c, list, count);
	else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else
		write (2, "error", 5);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	list;

	va_start(list, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 0)
				break ;
			check(*str, list, &count);
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	return (count);
}
