/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:56:09 by man               #+#    #+#             */
/*   Updated: 2023/05/17 15:55:24 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*findadd_fd(t_list **origin, int tgfd)
{
	t_list	*current_node;
	t_list	*prev_node;
	t_list	*new_node;

	current_node = *origin;
	prev_node = NULL;
	while (current_node)
	{
		if (current_node->fd == tgfd)
			return (current_node);
		prev_node = current_node;
		current_node = current_node->next;
	}
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->mod = NULL;
	new_node->fd = tgfd;
	new_node->next = NULL;
	if (prev_node == NULL)
		*origin = new_node;
	else
		prev_node->next = new_node;
	return (new_node);
}

int	malloc_fail(int flag, t_list **origin, t_list **cur_lst, char *tmp)
{
	if (!tmp && flag == 1)
	{
		if ((*cur_lst)->mod)
			free((*cur_lst)->mod);
		delete_node(cur_lst, origin);
		return (1);
	}
	if (!((*cur_lst)->mod) && flag == 2)
	{
		delete_node(cur_lst, origin);
		return (1);
	}
	return (0);
}

int	free_exception(char *tmp, t_list **origin, t_list **cur_lst, int i)
{
	free(tmp);
	if (i == 0)
		return (1);
	free((*cur_lst)->mod);
	(*cur_lst)->mod = NULL;
	delete_node(cur_lst, origin);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*origin = NULL;
	t_list			*cur_lst;
	char			*tmp;
	int				i;

	cur_lst = findadd_fd(&origin, fd);
	if (!cur_lst)
		return (NULL);
	while (1)
	{
		tmp = (char *)malloc(BUFFER_SIZE + 1);
		if (malloc_fail(1, &origin, &cur_lst, tmp))
			return (NULL);
		i = (int)read(fd, tmp, BUFFER_SIZE);
		if ((i == -1 || i == 0) && free_exception(tmp, &origin, &cur_lst, i))
			break ;
		else if (i == -1 || i == 0)
			return (NULL);
		cur_lst->mod = ft_strjoin(cur_lst->mod, tmp, &cur_lst, i);
		if (malloc_fail(2, &origin, &cur_lst, NULL))
			return (NULL);
		if (str_check(&cur_lst, NULL, 0) >= 0)
			break ;
	}
	return (make_exception(&origin, &cur_lst, str_check(&cur_lst, NULL, 0)));
}

int	str_check(t_list **cur_lst, const char *str, int flag)
{
	size_t	i;
	int		j;

	if (flag)
	{	
		if (!str)
			return (0);
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		j = 0;
		if (!(*cur_lst)->mod)
			return (-1);
		while ((*cur_lst)->mod[j])
		{
			if ((*cur_lst)->mod[j] == '\n')
				return (j);
			j++;
		}
		return (-1);
	}
}
