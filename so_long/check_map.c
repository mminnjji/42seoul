/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:59:48 by man               #+#    #+#             */
/*   Updated: 2023/08/03 14:47:00 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	check_map_wall(t_key *key)
{
	int	i;

	i = 0;
	while (i < key->height)
	{
		if (key->map[i][0] != '1' || key->map[i][key->width - 1] != '1')
		{
			write(1, "Error\nMap Wall Error\n", 22);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < key->width)
	{
		if (key->map[0][i] != '1' || key->map[key->height - 1][i] != '1')
		{
			write(1, "Error\nMap Wall Error\n", 21);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	check_map_rule_check(t_key *key, int *count, int *flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < key->height)
	{
		j = 0;
		while (j < key->width)
		{
			if (key->map[i][j] == 'E')
				count[0]++;
			else if (key->map[i][j] == 'P')
				count[1]++;
			else if (key->map[i][j] == 'C')
				count[2]++;
			else if (!(key->map[i][j] == '0' || key->map[i][j] == '1'))
				(*flag) = 1;
			j++;
		}
		i++;
	}
}

static int	check_map_rule(t_key *key)
{
	int	count[3];
	int	flag;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	flag = 0;
	check_map_rule_check(key, count, &flag);
	if (flag || count[0] != 1 || count[1] != 1 || count[2] < 1)
	{
		write(1, "Error\nMap Out Of Rule\n", 22);
		return (0);
	}
	return (1);
}

static int	check_map_width(t_key *key)
{
	int	i;

	i = 1;
	while (i < key->height)
	{
		if (ft_strlen(key->map[i]) != key->width)
		{
			write(1, "Error\nMap Not Rectangular\n", 26);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map(t_key *key)
{
	if (!check_map_width(key))
		return (0);
	if (!check_map_wall(key))
		return (0);
	if (!check_map_rule(key))
		return (0);
	if (!check_map_way(key))
		return (0);
	return (1);
}
