/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:11:39 by man               #+#    #+#             */
/*   Updated: 2023/07/16 17:24:07 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	cmd_move(char *cmd, t_deq *a, t_deq *b)
{
	if (ft_strcmp(cmd, "ra\n"))
		ra(a);
	else if (ft_strcmp(cmd, "rb\n"))
		rb(b);
	else if (ft_strcmp(cmd, "rr\n"))
		rr(a, b);
	else if (ft_strcmp(cmd, "rra\n"))
		rra(a);
	else if (ft_strcmp(cmd, "rrb\n"))
		rrb(b);
	else if (ft_strcmp(cmd, "rrr\n"))
		rrr(a, b);
	else if (ft_strcmp(cmd, "sa\n"))
		sa(a);
	else if (ft_strcmp(cmd, "sb\n"))
		sb(b);
	else if (ft_strcmp(cmd, "ss\n"))
		ss(a, b);
	else if (ft_strcmp(cmd, "pa\n"))
		pa(a, b);
	else if (ft_strcmp(cmd, "pb\n"))
		pb(a, b);
	else
		return (0);
	return (1);
}

int	check_cmd(t_deq *a, t_deq *b, int *flag)
{
	char	*cmd;

	*flag = 0;
	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		if (!cmd_move(cmd, a, b))
		{
			*flag = 1;
			return (0);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	if (b->list_size == 0 && check_sorted(a))
		return (1);
	else
		return (0);
}

static void	get_sorted(t_deq *a, t_deq *b)
{
	int	flag;

	flag = 0;
	if (!check_sorted(a))
	{
		if (check_cmd(a, b, &flag))
			write(1, "OK\n", 3);
		else if (flag == 0)
			write(1, "KO\n", 3);
		else
			write_error();
	}
}

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
	init_deq(a, b, list_size);
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
	get_sorted(a, b);
	return (ft_free(a, b));
}
