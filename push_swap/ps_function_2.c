/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:14:43 by man               #+#    #+#             */
/*   Updated: 2023/06/28 15:22:30 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deq *a)
{
	int	i;
	int	tmp;

	i = a->list_size -1;
	tmp = a->list[a->list_size -1];
	while (i > 0)
	{
		a->list[i] = a->list[i - 1];
		i--;
	}
	a->list[0] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_deq *b)
{
	int	i;
	int	tmp;

	i = b->list_size -1;
	tmp = b->list[b->list_size -1];
	while (i > 0)
	{
		b->list[i] = b->list[i - 1];
		i--;
	}
	b->list[0] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_deq *a, t_deq *b)
{
	int	i;
	int	tmp;

	i = a->list_size -1;
	tmp = a->list[a->list_size -1];
	while (i > 0)
	{
		a->list[i] = a->list[i - 1];
		i--;
	}
	a->list[0] = tmp;
	i = b->list_size -1;
	tmp = b->list[b->list_size -1];
	while (i > 0)
	{
		b->list[i] = b->list[i - 1];
		i--;
	}
	b->list[0] = tmp;
	write(1, "rr\n", 3);
}
