/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:27:39 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:49:48 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

long long	*re_assign(long long *list, char **res, int k)
{
	int			i;
	long long	*new_list;

	i = 0;
	while (res[i])
		i++;
	new_list = malloc(sizeof(long long) * (k + i + 1));
	i = 0;
	while (i < k)
	{
		new_list[i] = list[i];
		i++;
	}
	free(list);
	return (new_list);
}

long long	*make_list(int argc, char **argv, int *list_length)
{
	char		**res;
	long long	*list;
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	list = NULL;
	while (i++ < argc - 1)
	{
		res = ft_split(argv[i], ' ');
		j = 0;
		list = re_assign(list, res, k);
		while (res[j])
		{
			list[k] = ft_atoi(res[j]);
			free(res[j]);
			j++;
			k++;
		}
		free(res);
	}
	*list_length = k;
	return (list);
}
