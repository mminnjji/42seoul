/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:42:22 by man               #+#    #+#             */
/*   Updated: 2023/08/12 14:22:06 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	map_background(t_key *key, t_win *win)
{
	void	*img;
	int		img_size[2];
	int		i;
	int		j;

	i = 0;
	img = mlx_xpm_file_to_image(win->mlx, "textures/background.xpm", \
			&img_size[0], &img_size[1]);
	if (!img)
	{
		ft_printf("Error image file unexist.ent: %s\n", strerror(errno));
		exit(0);
	}
	while (i < key->height)
	{
		j = 0;
		while (j < key->width)
		{
			mlx_put_image_to_window(win->mlx, win->win, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	map_fences(t_key *key, t_win *win)
{
	int		i;
	int		j;
	void	*img;
	int		size[2];

	i = 0;
	j = 0;
	img = mlx_xpm_file_to_image(win->mlx, "textures/f.xpm", &size[0], &size[1]);
	if (!img)
	{
		ft_printf("Error image file unexist.ent: %s\n", strerror(errno));
		exit(0);
	}
	while (i < key->height)
	{
		j = 0;
		while (j < key->width)
		{
			if (key->map[i][j] == '1')
				mlx_put_image_to_window(win->mlx, win->win, img, \
						j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	map_collect(t_key *key, t_win *win)
{
	int		i;
	int		j;
	void	*img;
	int		size[2];

	i = 0;
	j = 0;
	img = mlx_xpm_file_to_image(win->mlx, "textures/c.xpm", &size[0], &size[1]);
	if (!img)
	{
		ft_printf("Error image file unexist.ent: %s\n", strerror(errno));
		exit(0);
	}
	while (i < key->height)
	{
		j = 0;
		while (j < key->width)
		{
			if (key->map[i][j] == 'C')
				mlx_put_image_to_window(win->mlx, win->win, img, \
						j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	map_end(t_key *key, t_win *win)
{
	int		i;
	int		j;
	void	*img;
	int		size[2];

	i = 0;
	j = 0;
	img = mlx_xpm_file_to_image(win->mlx, "textures/e.xpm", &size[0], &size[1]);
	if (!img)
	{
		ft_printf("Error image file unexist.ent: %s\n", strerror(errno));
		exit(0);
	}
	while (i < key->height)
	{
		j = 0;
		while (j < key->width)
		{
			if (key->map[i][j] == 'E')
				mlx_put_image_to_window(win->mlx, win->win, \
						img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	map_set(t_key *key, t_win *win)
{
	map_background(key, win);
	map_fences(key, win);
	map_collect(key, win);
	map_end(key, win);
	mlx_put_image_to_window(win->mlx, win->win, \
			win->img[win->count % 2], key->y, key->x);
	if (map_end_check(key))
		exit(0);
}
