/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:58:51 by man               #+#    #+#             */
/*   Updated: 2023/07/31 18:53:02 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closed(int key_code, t_key *key)
{
	(void)key_code;
	(void)key;
	exit(0);
	return (0);
}

void	map_image_set(t_win *win, t_key *key)
{
	key->x = key->x * 64;
	key->y = key->y * 64;
	key->win = win;
	map_set(key, win);
	mlx_hook(win->win, 3, 0, &key_press, key);
	mlx_hook(win->win, 17, 0, &closed, key);
	mlx_loop(win->mlx);
}
