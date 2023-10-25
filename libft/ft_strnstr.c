/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:06:21 by man               #+#    #+#             */
/*   Updated: 2023/04/03 18:10:02 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_all(int i, int j, const char *str, const char *to_find)
{
	int	a;

	a = 0;
	while (str[i + a] == to_find[a])
	{
		if (a == (j - 1))
			return (1);
		else if (a < j - 1)
			a++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (little[j])
		j++;
	if (j > 0)
	{
		while (big[i] && i <= len)
		{
			if (big[i] == little[0] && i + j <= len)
			{
				if (find_all(i, j, big, little))
					return ((char *)&big[i]);
			}
			i++;
		}
	}
	else
		return ((char *)big);
	return (0);
}
