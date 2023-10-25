/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:50:59 by man               #+#    #+#             */
/*   Updated: 2023/04/03 18:11:40 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *strs, char const *sep)
{
	char	*res;

	res = ft_calloc((ft_strlen(sep) + ft_strlen(strs) + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strcat(res, strs);
	ft_strcat(res, sep);
	res[ft_strlen(sep) + ft_strlen(strs)] = 0;
	return (res);
}
