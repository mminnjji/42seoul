/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:33:13 by man               #+#    #+#             */
/*   Updated: 2023/08/16 06:45:39 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"

static int	get_map_line(int fd)
{
	char	buf[2];
	int		i;
	int		count;

	i = read(fd, buf, 1);
	count = 0;
	while (i)
	{
		if (buf[0] == '\n')
			count++;
		i = read(fd, buf, 1);
	}
	return (count + 1);
}

static int	fd_error(void)
{
	write(1, "Error\nNot Valid\n", 16);
	return (0);
}

static void	get_map(char *argv, t_key *key)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(fd_error());
	key->height = get_map_line(fd);
	key->map = malloc(sizeof(char *) * (key->height + 1));
	if (!key->map)
		exit(0);
	close(fd);
	fd = open(argv, O_RDONLY);
	while (++i < key->height)
	{
		key->map[i] = get_next_line(fd);
		if (!key->map[i])
		{
			write(1, "Error\nMap Not Rectangular\n", 26);
			exit(0);
		}
		if (key->map[i][ft_strlen(key->map[i]) - 1] == '\n')
			key->map[i][ft_strlen(key->map[i]) - 1] = 0;
	}
	key->width = ft_strlen(key->map[0]);
}

int	main(int argc, char **argv)
{
	t_key	*key;
	t_win	*win;

	if (argc <= 1 || argc > 2)
	{
		write(1, "Error\nNot Valid\n", 16);
		return (0);
	}
	key = malloc(sizeof(t_key));
	if (!key)
		exit(0);
	get_map(argv[1], key);
	key_init(key);
	if (!check_map(key))
		exit(0);
	win = malloc(sizeof(t_win));
	if (!win)
		exit(0);
	win_init(win, key);
	map_image_set(win, key);
	free_all(key, NULL, NULL, NULL);
	return (0);
}
