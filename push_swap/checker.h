/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:25:55 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:35:46 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_deq
{
	long long	*list;
	int			list_size;
}	t_deq;

int			find_max(t_deq *deq);
void		indexing(t_deq *deq);
void		sa(t_deq *a);
void		sb(t_deq *b);
void		ss(t_deq *a, t_deq *b);
void		pa(t_deq *a, t_deq *b);
void		pb(t_deq *a, t_deq *b);
void		ra(t_deq *a);
void		rb(t_deq *b);
void		rr(t_deq *a, t_deq *b);
void		rra(t_deq *a);
void		rrb(t_deq *b);
void		rrr(t_deq *a, t_deq *b);
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
char		**ft_split(char const *str, char c);
int			check_sorted(t_deq *a);
long long	*make_list(int argc, char **argv, int *i);
char		**ft_split(char const *str, char c);
long long	*re_assign(long long *list, char **res, int k);
int			ft_strcmp(const char *s1, const char *s2);
char		*get_next_line(int fd);
int			check_cmd(t_deq *a, t_deq *b, int *flag);
int			write_error(void);
int			check_list(long long *list, int list_size);
int			init_deq(t_deq *a, t_deq *b, int argc);
int			ft_free(t_deq *a, t_deq *b);

#endif
