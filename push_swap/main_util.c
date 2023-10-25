/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:18:16 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:38:03 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	check_list(long long *list, int list_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < list_size)
	{
		if (list[i] > INT_MAX || list[i] < INT_MIN)
			return (write_error());
		i++;
	}
	i = 0;
	while (i < list_size)
	{
		j = i + 1;
		while (j < list_size)
		{
			if (list[i] == list[j])
				return (write_error());
			j++;
		}
		i++;
	}
	return (1);
}

int	init_deq(t_deq *a, t_deq *b, int argc)
{
	a->list = malloc(sizeof(int) * argc * 2);
	b->list = malloc(sizeof(int) * argc * 2);
	a->list_size = argc;
	b->list_size = 0;
	if (!a->list || !b->list)
		return (0);
	return (1);
}

int	ft_free(t_deq *a, t_deq *b)
{
	free(a->list);
	free(b->list);
	free(a);
	free(b);
	return (0);
}
