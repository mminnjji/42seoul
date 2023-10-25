/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function_c_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:21:39 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:31:28 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}
