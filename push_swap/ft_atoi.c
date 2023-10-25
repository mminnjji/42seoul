/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:17:43 by man               #+#    #+#             */
/*   Updated: 2023/06/28 15:39:24 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	plus;
	long long	sum;

	i = 0;
	plus = 1;
	sum = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) \
				|| str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			plus *= -1;
	while (ft_isdigit(str[i]))
	{
		sum *= 10;
		sum += (str[i++] - '0');
	}
	if ((!ft_isdigit(str[i]) && str[i] != 0))
		return (1000000000000);
	if (sum * plus > INT_MAX || sum * plus < INT_MIN)
		return (1000000000000);
	return (sum * plus);
}
