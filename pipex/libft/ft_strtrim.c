/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:31:52 by man               #+#    #+#             */
/*   Updated: 2023/04/03 18:11:56 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_in_set(char c, char const *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_first_pointer(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (char_in_set(s1[i], set))
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	get_last_pointer(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (char_in_set(s1[i - 1], set))
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	first_point;
	size_t	last_point;
	int		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	first_point = get_first_pointer(s1, set);
	if (first_point == ft_strlen(s1))
		return (ft_strdup(""));
	last_point = get_last_pointer(s1, set);
	str = (char *)malloc((last_point - first_point + 1) * sizeof(char));
	if (!str)
		return (0);
	j = 0;
	while (first_point + j < last_point)
	{
		str[j] = s1[first_point + j];
		j++;
	}
	str[j] = 0;
	return (str);
}
