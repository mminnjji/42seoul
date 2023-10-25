/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:27:43 by man               #+#    #+#             */
/*   Updated: 2023/07/16 17:26:10 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long long	*list;
	int			list_size;
	int			j;
	t_deq		*a;
	t_deq		*b;

	a = malloc(sizeof(t_deq));
	b = malloc(sizeof(t_deq));
	list = make_list(argc, argv, &list_size);
	if (!init_deq(a, b, list_size))
		return (write_error());
	if (!check_list(list, list_size))
		return (ft_free(a, b));
	j = 0;
	while (j < list_size)
	{
		a->list[list_size - 1 - j] = list[j];
		j++;
	}
	free(list);
	indexing(a);
	if (!check_sorted(a))
		sort(a, b);
	j = 0;
	return (ft_free(a, b));
}
