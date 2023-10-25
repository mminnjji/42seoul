/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:52:06 by man               #+#    #+#             */
/*   Updated: 2023/05/20 14:16:16 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	int				fd;
	char			*mod;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*make_exception(t_list **origin, t_list **cur_lst, int i);
char	*ft_strjoin(char *mod, char *tmp, t_list **cur_lst, int end);
int		null_exception(t_list **origin, t_list **cur_lst, char *res);
char	*make_res(char *res, char *tmp, t_list **cur_lst, int i);
void	delete_node(t_list **cur_lst, t_list **origin);
t_list	*findadd_fd(t_list **origin, int tgfd);
int		free_exception(char *tmp, t_list **origin, t_list **cur_lst, int i);
int		str_check(t_list **cur_lst, const char *str, int flag);
int		malloc_fail(int flag, t_list **origin, t_list **cur_lst, char *tmp);

#endif
