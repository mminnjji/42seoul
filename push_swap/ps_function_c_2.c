/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function_c_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:30:32 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:30:50 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}
