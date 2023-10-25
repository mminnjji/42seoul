/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:29:55 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:30:06 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
