/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:50:33 by man               #+#    #+#             */
/*   Updated: 2023/08/16 06:36:40 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	key_move(t_key *key, t_win *win)
{
	if (win->flag == 'w')
		key->x = key->x - 64;
	if (win->flag == 's')
		key->x = key->x + 64;
	if (win->flag == 'a')
		key->y = key->y - 64;
	if (win->flag == 'd')
		key->y = key->y + 64;
}

int	map_end_check(t_key *key)
{
	int	i;
	int	j;

	i = 0;
	if (key->map[key->x / 64][key->y / 64] == 'E')
	{
		while (i < key->height)
		{
			j = 0;
			while (j < key->width)
			{
				if (key->map[i][j] == 'C')
					return (0);
				j++;
			}
			i++;
		}
		return (1);
	}
	if (key->map[key->x / 64][key->y / 64] == 'C')
	{
		key->map[key->x / 64][key->y / 64] = '0';
		map_set(key, key->win);
	}
	return (0);
}

int	key_press(int keycode, t_key *key)
{
	if (keycode == 53)
		exit(0);
	key->win->flag = '0';
	if (map_end_check(key))
		key->win->flag = '0';
	else if (keycode == 13)
		key->win->flag = 'w';
	else if (keycode == 1)
		key->win->flag = 's';
	else if (keycode == 0)
		key->win->flag = 'a';
	else if (keycode == 2)
		key->win->flag = 'd';
	if (!map_end_check(key))
	{
		key_move(key, key->win);
		key_error(key, key->win);
		map_set(key, key->win);
	}
	return (0);
}

void	key_error(t_key *key, t_win *win)
{
	if (key->map[key->x / 64][key->y / 64] == '1')
	{
		if (win->flag == 's')
			key->x = key->x - 64;
		if (win->flag == 'w')
			key->x = key->x + 64;
		if (win->flag == 'a')
			key->y = key->y + 64;
		if (win->flag == 'd')
			key->y = key->y - 64;
		win->flag = '0';
	}
	else if (win->flag == 'd' || win->flag == 'a' || win->flag == 's' \
			|| win->flag == 'w')
	{
		win->count++;
		ft_printf("move_count: %d\n", win->count);
	}
}
