/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:03:59 by man               #+#    #+#             */
/*   Updated: 2023/04/03 18:08:30 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*str;

	temp = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		if (temp < str)
			temp[i] = (unsigned char)str[i];
		else
			temp[n - 1 - i] = (unsigned char)str[n - 1 - i];
		i++;
	}
	return (temp);
}
