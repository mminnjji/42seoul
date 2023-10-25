/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:44:40 by man               #+#    #+#             */
/*   Updated: 2023/08/12 14:21:49 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	free_key(t_key *key)
{
	int	i;

	i = 0;
	while (i < key->height)
	{
		free(key->map[i]);
		i++;
	}
	free(key->map);
	free(key);
}

void	free_map(char **map, t_key *key)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < key->height)
		{
			if (map[i])
				free(map[i]);
			else
				break ;
			i++;
		}
		free(map);
	}
}

int	free_all(t_key *key, char **map, t_node *node, t_win *win)
{
	t_node	*tmp;
	int		i;

	if (map)
		free_map(map, key);
	if (key && !map)
		free_key(key);
	i = 0;
	if (node)
	{
		while (node->next)
		{
			tmp = node;
			node = node->next;
			free(tmp);
			i++;
		}
		free(node);
	}
	if (win)
		free(win);
	return (0);
}

void	key_init(t_key *key)
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
			if (key->map[i][j] == 'P')
			{
				key->x = i;
				key->y = j;
			}
			j++;
		}
		i++;
	}
}

void	win_init(t_win *win, t_key *key)
{
	int	img_size[2];

	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 64 * key->width, 64 * \
			key->height, "so_long");
	win->img[0] = mlx_xpm_file_to_image(win->mlx, "textures/slime1.xpm", \
			&img_size[0], &img_size[1]);
	if (!win->img[0])
	{
		ft_printf("Error image file unexist.ent: %s\n", strerror(errno));
		exit(0);
	}
	win->img[1] = mlx_xpm_file_to_image(win->mlx, "textures/slime5.xpm", \
			&img_size[0], &img_size[1]);
	if (!win->img[1])
	{
		ft_printf("Error image file unexist.ent: %s\n", strerror(errno));
		exit(0);
	}
	win->count = 0;
}
