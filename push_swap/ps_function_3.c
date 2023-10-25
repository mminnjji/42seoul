/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:21:39 by man               #+#    #+#             */
/*   Updated: 2023/06/28 15:22:37 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deq *a)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = a->list[0];
	while (i < a->list_size)
	{
		a->list[i - 1] = a->list[i];
		i++;
	}
	a->list[a->list_size -1] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_deq *b)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = b->list[0];
	while (i < b->list_size)
	{
		b->list[i - 1] = b->list[i];
		i++;
	}
	b->list[b->list_size -1] = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_deq *a, t_deq *b)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = a->list[0];
	while (i < a->list_size)
	{
		a->list[i - 1] = a->list[i];
		i++;
	}
	a->list[a->list_size -1] = tmp;
	i = 1;
	tmp = b->list[0];
	while (i < b->list_size)
	{
		b->list[i - 1] = b->list[i];
		i++;
	}
	b->list[b->list_size -1] = tmp;
	write(1, "rrr\n", 4);
}
