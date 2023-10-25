/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_way_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:38:13 by man               #+#    #+#             */
/*   Updated: 2023/08/12 14:21:05 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*ft_lstnew(int x, int y)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node -> next = NULL;
	node -> x = x;
	node -> y = y;
	return (node);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}

void	copy_map(char **map, t_key *key)
{
	int		i;
	int		j;

	i = 0;
	while (i < key->height)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * (key->width + 1));
		if (!map[i])
			exit(0);
		while (j < key->width)
		{
			map[i][j] = key->map[i][j];
			j++;
		}
		i++;
	}
}

void	map_init(char **map, t_key *key)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < key->height)
	{
		j = 0;
		while (j < key-> width)
		{
			if (map[i][j] == '2')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}
