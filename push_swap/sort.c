/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:18 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:32:41 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pivot(t_deq *a, int p[])
{
	p[0] = a->list_size / 5;
	p[1] = p[0] * 2;
	p[2] = p[0] * 3;
	p[3] = p[0] * 4;
}

static void	p_sort1(t_deq *a, t_deq *b, int p[])
{
	int	j;
	int	tmp;

	j = a->list_size;
	tmp = a->list_size - 1;
	while (j--)
	{
		if (a->list[tmp] >= p[2] || a->list[tmp] < p[0])
			ra(a);
		else if (a->list[tmp] < p[2] || a->list[tmp] >= p[0])
		{
			pb(a, b);
			if (b->list[b->list_size - 1] < p[1])
				rb(b);
		}
	}
}

static void	p_sort2(t_deq *a, t_deq *b, int p[])
{
	int	j;

	j = a->list_size;
	while (j--)
	{
		if (a->list[a->list_size - 1] >= p[3])
			ra(a);
		else
		{
			pb(a, b);
			if (b->list[b->list_size - 1] <= p[0])
				rb(b);
		}
	}
}

static void	get_place(t_deq *a, t_deq *b)
{
	int	flag;
	int	min[2];

	find_min(a, b, &flag, min);
	move_ab(a, b, flag, min);
}

void	sort(t_deq *a, t_deq *b)
{
	int	p[4];
	int	j;

	if (a->list_size <= 6)
		fast_sort(a, b);
	else
	{
		pivot(a, p);
		p_sort1(a, b, p);
		p_sort2(a, b, p);
		j = a->list_size;
		while (j-- > 3)
			pb(a, b);
		three_sort(a, 0);
		while (b->list_size)
			get_place(a, b);
		fin_sort(a);
	}
}
