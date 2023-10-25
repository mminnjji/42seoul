/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:33:25 by man               #+#    #+#             */
/*   Updated: 2023/07/16 16:35:36 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void		sort(t_deq *a, t_deq *b);
void		three_sort(t_deq *a, int flag);
void		find_min(t_deq *a, t_deq *b, int *flag, int min[]);
void		move_ab(t_deq *a, t_deq *b, int flag, int min[]);
void		rarb(t_deq *a, t_deq *b, int min[]);
void		rrarb(t_deq *a, t_deq *b, int min[]);
void		rarrb(t_deq *a, t_deq *b, int min[]);
void		rrarrb(t_deq *a, t_deq *b, int min[]);
void		fin_sort(t_deq *a);
int			check_sorted(t_deq *a);
void		fast_sort(t_deq *a, t_deq *b);
long long	*make_list(int argc, char **argv, int *i);
char		**ft_split(char const *str, char c);
long long	*re_assign(long long *list, char **res, int k);
int			write_error(void);
int			check_list(long long *list, int list_size);
int			init_deq(t_deq *a, t_deq *b, int argc);
int			ft_free(t_deq *a, t_deq *b);

#endif
