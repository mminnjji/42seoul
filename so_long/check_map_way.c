/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:52:52 by man               #+#    #+#             */
/*   Updated: 2023/08/12 14:21:19 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	map_check_ec(char **map, t_key *key)
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
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_node(int x, int y, char **map, t_node **node)
{
	t_node	*tmp;

	if (map[x][y] == 'C' || map[x][y] == 'E')
	{
		map[x][y] = '0';
		return (1);
	}
	if (map[x][y] == '0')
	{
		tmp = ft_lstlast(*node);
		tmp->next = ft_lstnew(x, y);
		map[x][y] = '2';
	}
	return (0);
}

static int	get_way_return(char **map, t_node **node, t_key *key, t_node *tmp)
{
	if (*node != NULL)
	{
		(*node) = tmp;
		free_all(NULL, NULL, (*node)->next, NULL);
		(*node)->next = NULL;
		map_init(map, key);
		if (map_check_ec(map, key))
			get_way(map, node, key);
		else
		{
			free(*node);
			return (1);
		}
	}
	else
		free_all(NULL, NULL, tmp, NULL);
	if (!map_check_ec(map, key))
		return (1);
	return (0);
}

int	get_way(char **map, t_node **node, t_key *key)
{
	t_node	*tmp;

	tmp = (*node);
	map[(*node)->x][(*node)->y] = '0';
	while ((*node) != NULL)
	{
		if ((*node)->x - 1 >= 0)
			if (check_node((*node)->x - 1, (*node)->y, map, node))
				break ;
		if ((*node)->y - 1 >= 0)
			if (check_node((*node)->x, (*node)->y - 1, map, node))
				break ;
		if ((*node)->x + 1 < key->height)
			if (check_node((*node)->x + 1, (*node)->y, map, node))
				break ;
		if ((*node)->y + 1 < key->width)
			if (check_node((*node)->x, (*node)->y + 1, map, node))
				break ;
		(*node) = (*node)->next;
	}
	return (get_way_return(map, node, key, tmp));
}

int	check_map_way(t_key *key)
{
	char	**map;
	t_node	*node;
	int		res;

	map = malloc(sizeof(char *) * (key->height + 1));
	if (!map)
		exit(0);
	copy_map(map, key);
	node = ft_lstnew(key->x, key->y);
	if (!node)
		exit(0);
	res = get_way(map, &node, key);
	free_all(key, map, NULL, NULL);
	if (!res)
		write(1, "Error\nMap No Way\n", 17);
	return (res);
}
