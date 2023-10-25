/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function_c_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:31:06 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:31:12 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_deq *a)
{
	int	tmp;

	if (a->list_size <= 1)
		return ;
	tmp = a->list[a->list_size - 1];
	a->list[a->list_size - 1] = a->list[a->list_size - 2];
	a->list[a->list_size - 2] = tmp;
}

void	sb(t_deq *b)
{
	int	tmp;

	if (b->list_size <= 1)
		return ;
	tmp = b->list[b->list_size - 1];
	b->list[b->list_size - 1] = b->list[b->list_size - 2];
	b->list[b->list_size - 2] = tmp;
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
}

void	pa(t_deq *a, t_deq *b)
{
	if (b->list_size < 1)
		return ;
	a->list[a->list_size] = b->list[b->list_size - 1];
	b->list_size--;
	a->list_size++;
}

void	pb(t_deq *a, t_deq *b)
{
	if (a->list_size < 1)
		return ;
	b->list[b->list_size] = a->list[a->list_size - 1];
	a->list_size--;
	b->list_size++;
}
