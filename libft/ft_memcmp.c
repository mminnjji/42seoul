/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:03:18 by man               #+#    #+#             */
/*   Updated: 2023/03/27 19:05:55 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned int	i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)ptr1;
	temp2 = (unsigned char *)ptr2;
	i = 0;
	while (i < num)
	{
		if (temp1[i] != temp2[i])
			return ((unsigned int)temp1[i] - (unsigned int)temp2[i]);
		i++;
	}
	return (0);
}
