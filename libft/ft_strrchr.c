/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:06:37 by man               #+#    #+#             */
/*   Updated: 2023/04/03 18:09:12 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;
	char	*res;

	tmp = (char *) str;
	res = 0;
	while (*tmp != 0)
	{
		if (*tmp == (char)c)
		{
			res = tmp;
		}
		tmp++;
	}
	if (*tmp == (char)c)
		return (tmp);
	return (res);
}
