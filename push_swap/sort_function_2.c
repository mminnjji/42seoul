/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:08:18 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:33:01 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	*re_assign(long long *list, char **res, int k)
{
	int			i;
	long long	*new_list;

	i = 0;
	while (res[i])
		i++;
	new_list = malloc(sizeof(long long) * (k + i + 1));
	i = 0;
	while (i < k)
	{
		new_list[i] = list[i];
		i++;
	}
	free(list);
	return (new_list);
}

long long	*make_list(int argc, char **argv, int *list_length)
{
	char		**res;
	long long	*list;
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	list = NULL;
	while (i++ < argc - 1)
	{
		res = ft_split(argv[i], ' ');
		j = 0;
		list = re_assign(list, res, k);
		while (res[j])
		{
			list[k] = ft_atoi(res[j]);
			free(res[j]);
			j++;
			k++;
		}
		free(res);
	}
	*list_length = k;
	return (list);
}

void	move_ab(t_deq *a, t_deq *b, int flag, int min[])
{
	if (flag == 0)
		rarb(a, b, min);
	if (flag == 1)
		rarrb(a, b, min);
	if (flag == 2)
		rrarb(a, b, min);
	if (flag == 3)
		rrarrb(a, b, min);
	pa(a, b);
}

void	fin_sort(t_deq *a)
{
	int	i;

	i = 0;
	while (i < a->list_size)
	{
		if (a->list[i] == 0)
			break ;
		i++;
	}
	if (i + 1 > a->list_size - i - 1)
	{
		while (a->list_size - i - 1)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i + 1)
		{
			rra(a);
			i--;
		}
	}
}

void	three_sort(t_deq *a, int flag)
{
	if (flag == 0)
	{
		if (a->list[a->list_size - 1] > a->list[a->list_size - 2])
			sa(a);
		if (a->list[a->list_size - 2] > a->list[a->list_size - 3])
			rra(a);
		if (a->list[a->list_size - 1] > a->list[a->list_size - 2])
			sa(a);
	}
	else
	{
		if (a->list[a->list_size - 1] < a->list[a->list_size - 2])
			sb(a);
		if (a->list[a->list_size - 2] < a->list[a->list_size - 3])
			rrb(a);
		if (a->list[a->list_size - 1] < a->list[a->list_size - 2])
			sb(a);
	}
}
