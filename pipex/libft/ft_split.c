/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:29:27 by man               #+#    #+#             */
/*   Updated: 2023/10/21 13:16:42 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_line(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
		{
			if (str[i] == '\'' || str[i] == '\"')
				pass_idx(str, &i);
			i++;
		}
	}
	return (count);
}

char	*str_alc(char *str, char c, int *start, int *end)
{
	char	*res;
	int		count;

	count = 0;
	while (str[*start] == c)
		(*start)++;
	(*end) = (*start);
	while (str[*start] != c && str[*start])
	{
		if (str[*start] == '\'' || str[*start] == '\"')
			count += pass_idx(str, start);
		(*start)++;
	}
	res = malloc(sizeof(char) * ((*start) - (*end) + count + 1));
	if (!res)
		exit(0);
	return (res);
}

int	str_cpy_util(char *res, char *str, int end, int *i)
{
	if (str[end] == '\'')
	{
		while (str[end] == '\'')
			end++;
		if (str[end] == '\"')
			return (0);
		while (str[end + (*i)] != '\'' && str[end + (*i)] != '\"')
		{
			res[(*i)] = str[end + (*i)];
			(*i)++;
		}
	}
	else if (str[end] == '\"')
	{
		while (str[end] == '\"')
			end++;
		while (str[end + (*i)] != '\"')
		{
			res[(*i)] = str[end + (*i)];
			(*i)++;
		}
	}
	else
		return (2);
	return (1);
}

int	str_cpy(char *res, char *str, int start, int end)
{
	int	i;
	int	n;

	i = 0;
	n = str_cpy_util(res, str, end, &i);
	if (n == 2)
	{
		i = 0;
		while (end + i < start)
		{
			res[i] = str[end + i];
			i++;
		}
	}
	else if (n == 0)
	{
		res[i] = 0;
		return (0);
	}
	res[i] = 0;
	return (1);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	res = malloc(sizeof(char *) * (get_line(str, c) + 1));
	if (!res)
		exit(0);
	while (i < get_line(str, c))
	{
		res[i] = str_alc(str, c, &start, &end);
		if (!str_cpy(res[i], str, start, end))
			res[i] = "{print}";
		i++;
	}
	res[i] = 0;
	return (res);
}
