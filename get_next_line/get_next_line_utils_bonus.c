/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:03:08 by man               #+#    #+#             */
/*   Updated: 2023/05/20 14:17:01 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *mod, char *tmp, t_list **cur_lst, int end)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tmp[end] = 0;
	new = (char *)malloc(str_check(NULL, mod, 1) + str_check(NULL, tmp, 1) + 1);
	if (!new)
	{
		if ((*cur_lst)->mod)
			free((*cur_lst)->mod);
		free(tmp);
		return (NULL);
	}
	while (mod && mod[++i])
		new[i] = mod[i];
	if (i == -1)
		i++;
	while (tmp[++j])
		new[i + j] = tmp[j];
	free(mod);
	free(tmp);
	new[i + j] = 0;
	return (new);
}

char	*make_exception(t_list **origin, t_list **cur_lst, int i)
{
	char	*res;
	char	*tmp;

	res = (char *)malloc(i + 2);
	if (!null_exception(origin, cur_lst, res))
		return (0);
	if (i < 0)
	{
		free(res);
		res = (*cur_lst)->mod;
		(*cur_lst)->mod = 0;
		return (res);
	}
	tmp = (char *)malloc(str_check(NULL, ((*cur_lst)->mod), 1) - i);
	if (!tmp)
	{
		free(res);
		free((*cur_lst)->mod);
		delete_node(cur_lst, origin);
		return (0);
	}
	return (make_res(res, tmp, cur_lst, i));
}

char	*make_res(char *res, char *tmp, t_list **cur_lst, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		res[j] = (*cur_lst)->mod[j];
		j++;
	}
	res[j] = 0;
	while (j <= str_check(NULL, (*cur_lst)->mod, 1))
	{
		tmp[j - i - 1] = (*cur_lst)->mod[j];
		j++;
	}
	free((*cur_lst)->mod);
	(*cur_lst)->mod = tmp;
	if (!str_check(NULL, res, 1))
		free(tmp);
	return (res);
}

int	null_exception(t_list **origin, t_list **cur_lst, char *res)
{
	if (!res)
	{
		free((*cur_lst)->mod);
		if ((*cur_lst)->next == NULL)
			delete_node(cur_lst, origin);
		return (0);
	}
	if (!((*cur_lst)->mod))
	{
		(*cur_lst)->fd = -3;
		free(res);
		delete_node(cur_lst, origin);
		return (0);
	}
	if (!str_check(NULL, (*cur_lst)->mod, 1))
	{
		free(res);
		free((*cur_lst)->mod);
		delete_node(cur_lst, origin);
		return (0);
	}
	return (1);
}

void	delete_node(t_list **cur_lst, t_list **origin)
{
	t_list	*prev_node;
	t_list	*current_node;

	prev_node = NULL;
	current_node = *origin;
	if (*cur_lst == NULL || origin == NULL || *origin == NULL)
		return ;
	while (current_node != NULL)
	{
		if (current_node == (*cur_lst))
			break ;
		prev_node = current_node;
		current_node = current_node->next;
	}
	if (current_node == NULL)
		return ;
	if (prev_node == NULL)
		*origin = current_node->next;
	else
		prev_node->next = current_node->next;
	free(current_node);
}
