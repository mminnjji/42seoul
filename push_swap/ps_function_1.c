/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:11:36 by man               #+#    #+#             */
/*   Updated: 2023/06/28 15:14:30 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deq *a)
{
	int	tmp;

	if (a->list_size <= 1)
		return ;
	tmp = a->list[a->list_size - 1];
	a->list[a->list_size - 1] = a->list[a->list_size - 2];
	a->list[a->list_size - 2] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_deq *b)
{
	int	tmp;

	if (b->list_size <= 1)
		return ;
	tmp = b->list[b->list_size - 1];
	b->list[b->list_size - 1] = b->list[b->list_size - 2];
	b->list[b->list_size - 2] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_deq *a, t_deq *b)
{
	int	tmp;

	if (a->list_size <= 1 || b->list_size <= 1)
		return ;
	tmp = a->list[a->list_size - 1];
	a->list[a->list_size - 1] = a->list[a->list_size - 2];
	a->list[a->list_size - 2] = tmp;
	tmp = b->list[b->list_size - 1];
	b->list[b->list_size - 1] = b->list[b->list_size - 2];
	b->list[b->list_size - 2] = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_deq *a, t_deq *b)
{
	if (b->list_size < 1)
		return ;
	a->list[a->list_size] = b->list[b->list_size - 1];
	b->list_size--;
	a->list_size++;
	write(1, "pa\n", 3);
}

void	pb(t_deq *a, t_deq *b)
{
	if (a->list_size < 1)
		return ;
	b->list[b->list_size] = a->list[a->list_size - 1];
	a->list_size--;
	b->list_size++;
	write(1, "pb\n", 3);
}
