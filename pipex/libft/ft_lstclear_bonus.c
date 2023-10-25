/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:20 by man               #+#    #+#             */
/*   Updated: 2023/03/24 19:24:37 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	while ((*lst)->next)
	{
		if (del)
			(*del)((*lst)->content);
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
	if (del)
		(*del)((*lst)->content);
	free(*lst);
	(*lst) = NULL;
}
