/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:22:59 by man               #+#    #+#             */
/*   Updated: 2023/06/28 15:27:58 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rarb(t_deq *a, t_deq *b, int min[])
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < min[0] && i < min[1])
	{
		rr(a, b);
		j++;
		i++;
	}
	while (j < min[0])
	{
		ra(a);
		j++;
	}
	while (i < min[1])
	{
		rb(b);
		i++;
	}
}

void	rrarb(t_deq *a, t_deq *b, int min[])
{
	int	j;

	j = 0;
	while (j < min[0])
	{
		rra(a);
		j++;
	}
	j = 0;
	while (j < min[1])
	{
		rb(b);
		j++;
	}
}

void	rarrb(t_deq *a, t_deq *b, int min[])
{
	int	j;

	j = 0;
	while (j < min[0])
	{
		ra(a);
		j++;
	}
	j = 0;
	while (j < min[1])
	{
		rrb(b);
		j++;
	}
}

void	rrarrb(t_deq *a, t_deq *b, int min[])
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < min[0] && i < min[1])
	{
		rrr(a, b);
		j++;
		i++;
	}
	while (j < min[0])
	{
		rra(a);
		j++;
	}
	while (i < min[1])
	{
		rrb(b);
		i++;
	}
}
