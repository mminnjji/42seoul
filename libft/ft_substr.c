/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:45:19 by man               #+#    #+#             */
/*   Updated: 2023/04/03 18:11:13 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_malloc(char const *s, size_t str_len, size_t len, size_t start)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (str_len - len + 1));
	if (!str)
		return (0);
	while (i < str_len - len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	i = 0;
	str = NULL;
	str_len = (size_t)ft_strlen(s);
	if ((size_t)start + len <= str_len)
	{
		str = str_malloc(s, len, 0, (size_t)start);
	}
	else if ((size_t)start + len > str_len && start < str_len)
	{
		str = str_malloc(s, str_len, (size_t)start, (size_t)start);
	}
	else if ((size_t)start >= ft_strlen(s))
		str = str_malloc(s, 0, 0, 0);
	return (str);
}
