/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:11:08 by k3                #+#    #+#             */
/*   Updated: 2020/10/23 21:22:34 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF 1024
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_ps
{
	int	a[BUFF];
	int	b[BUFF];
	int	a_c;
	int	b_c;
	int	out_en;
}				t_ps;

void			sa(t_ps *ps);
void			sb(t_ps *ps);
void			ra(t_ps *ps);
void			rb(t_ps *ps);
void			rra(t_ps *ps);
void			rrb(t_ps *ps);
void			rrr(t_ps *ps);
void			up_stack(int *arg);
void			down_stack(int *arg);
void			pa(t_ps *ps);
void			pb(t_ps *ps);
int				find_small(t_ps *ps, char c);
int				find_max(t_ps *ps, char c);
int				smart_rt(t_ps *ps, int min, int chunk, char c);
void			clear_stack(t_ps *ps);
int				chk_inp(int ac, char **av, t_ps *ps);
int				chk_sort(t_ps *ps);
void			sort_3(t_ps *ps);
void			put_error();

#endif
