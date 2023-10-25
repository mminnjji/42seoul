/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:33:40 by man               #+#    #+#             */
/*   Updated: 2023/07/16 17:24:26 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_deq *deq)
{
	long long	max;
	int			idx;

	max = -1000000000000;
	idx = 0;
	while (idx < deq->list_size)
	{
		if (max < deq->list[idx])
			max = deq->list[idx];
		idx++;
	}
	idx = 0;
	while (idx < deq->list_size)
	{
		if (max == deq->list[idx])
		{
			deq->list[idx] = -1000000000000;
			return (idx);
		}
		idx++;
	}
	return (-1);
}

void	indexing(t_deq *deq)
{
	long long	*idx_list;
	int			idx;
	int			max_idx;

	idx_list = (long long *)malloc(sizeof(long long) * deq->list_size);
	if (!idx_list)
		exit(0);
	idx = deq->list_size - 1;
	while (idx >= 0)
	{
		max_idx = find_max(deq);
		idx_list[max_idx] = idx;
		idx--;
	}
	free(deq->list);
	deq->list = idx_list;
}

int	check_sorted(t_deq *a)
{
	int	i;
	int	max;

	i = 0;
	max = a->list_size - 1;
	while (i <= max)
	{
		if (a->list[i] != max - i)
			return (0);
		i++;
	}
	return (1);
}

static void	fast_sort_2(t_deq *a, t_deq *b)
{
	int	sizea;
	int	sizeb;

	sizea = a->list_size;
	sizeb = b->list_size;
	if (sizea == 3)
		three_sort(a, 0);
	if (sizeb == 3)
		three_sort(b, 1);
	if (sizea == 2 && a->list[sizea - 1] > a->list[sizea - 2])
		sa(a);
	if (sizeb == 2 && b->list[sizeb - 1] < b->list[sizeb - 2])
		sb(a);
	while (sizeb--)
		pa(a, b);
}

void	fast_sort(t_deq *a, t_deq *b)
{
	int	size;
	int	i;

	size = a->list_size;
	i = 0;
	if (size >= 4)
	{
		while (i < size)
		{
			if (a->list[a->list_size - 1] < size / 2)
				pb(a, b);
			else
				ra(a);
			i++;
		}
	}
	fast_sort_2(a, b);
}
