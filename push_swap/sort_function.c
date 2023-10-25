/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:01:39 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:33:37 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_maxmin(t_deq *a, int flag)
{
	int	i;
	int	val;

	i = 0;
	if (flag == 0)
	{
		while (i < a->list_size)
		{
			if (i == 0 || a->list[i] > val)
				val = a->list[i];
			i++;
		}
	}
	if (flag == 1)
	{
		while (i < a->list_size)
		{
			if (i == 0 || a->list[i] < val)
				val = a->list[i];
			i++;
		}
	}
	return (val);
}

static int	a_idx_move(t_deq *a, int data, int *flag)
{
	int	idx;

	idx = 0;
	while (idx < a->list_size)
	{
		if (a->list[idx] == data)
			break ;
		idx++;
	}
	if (a->list_size - idx - 1 < idx + 1)
		return (a->list_size - idx - 1);
	else
	{
		*flag = 2;
		return (idx + 1);
	}
}

static int	a_minmove(t_deq *a, int data, int *flag)
{
	int	min;
	int	max;
	int	a_idx;
	int	i;

	a_idx = 1;
	i = 0;
	*flag = 0;
	max = a_maxmin(a, 0);
	min = a_maxmin(a, 1);
	if (data > max || data < min)
		return (a_idx_move(a, min, flag));
	if (a->list[a->list_size - 1] > data && a->list[0] < data)
		return (0);
	while (i < a->list_size - 1)
	{
		if (a->list[i] > data && a->list[i + 1] < data)
			return (a_idx_move(a, a->list[i], flag));
		i++;
	}
	return (-1);
}

void	find_min(t_deq *a, t_deq *b, int *flag, int min[])
{
	int	i;
	int	move[2];
	int	flag_b;
	int	flag_a;

	i = 0;
	while (i < b->list_size)
	{
		flag_b = 0;
		move[0] = a_minmove(a, b->list[i], &flag_a);
		if (i >= b->list_size / 2)
			move[1] = b->list_size - i - 1;
		else
		{
			flag_b = 1;
			move[1] = i + 1;
		}
		if (i == 0 || min[0] + min[1] > move[0] + move[1])
		{
			min[0] = move[0];
			min[1] = move[1];
			*flag = flag_a + flag_b;
		}
		i++;
	}
}
