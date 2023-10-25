/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:43:52 by man               #+#    #+#             */
/*   Updated: 2023/03/18 20:29:07 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elt_count, size_t elt_size)
{
	void	*tmp;

	tmp = malloc(elt_count * elt_size);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, elt_size * elt_count);
	return (tmp);
}
