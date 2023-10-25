/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:46:59 by man               #+#    #+#             */
/*   Updated: 2023/08/16 06:37:05 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img[2];
	char	flag;
	int		count;
}	t_win;

typedef struct s_key
{
	int				width;
	int				height;
	char			**map;
	int				x;
	int				y;
	struct s_win	*win;
}	t_key;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

int		check_map_way(t_key *key);
int		check_map(t_key *key);
void	map_image_set(t_win *win, t_key *key);
int		map_end_check(t_key *key);
void	key_move(t_key *key, t_win *win);
int		key_press(int keycode, t_key *key);
void	key_error(t_key *key, t_win *win);
void	map_set(t_key *key, t_win *win);
void	key_init(t_key *key);
void	win_init(t_win *win, t_key *key);
int		free_all(t_key *key, char **map, t_node *node, t_win *win);
void	free_map(char **map, t_key *key);
void	free_key(t_key *key);
int		get_way(char **map, t_node **node, t_key *key);
t_node	*ft_lstnew(int x, int y);
t_node	*ft_lstlast(t_node *lst);
void	copy_map(char **map, t_key *key);
void	map_init(char **map, t_key *key);
char	*ft_itoa(int n);
void	print_count(int count, t_win *win);

#endif
