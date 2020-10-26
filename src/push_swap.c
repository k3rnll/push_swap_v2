/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:11:44 by k3                #+#    #+#             */
/*   Updated: 2020/10/24 21:21:27 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	mv_a(t_ps *ps, int chunk)
{
	int i;
	int min;

	min = find_small(ps, 'a');
	while (ps->a_c)
	{
		i = 0;
		while (ps->a_c && i < chunk)
		{
			if (ps->a_c < 4 && chunk == 1)
			{
				sort_3(ps);
				ps->a_c = 0;
				break ;
			}
			if (smart_rt(ps, min, chunk, 'a'))
			{
				smart_rt(ps, min, chunk / 2, 'b');
				pb(ps);
			}
			else
				i++;
		}
		min += chunk;
	}
}

int		main(int ac, char **av)
{
	t_ps	*ps;
	int		chunk;

	if (ac < 3)
		exit(0);
	if (!(ps = (t_ps*)malloc(sizeof(*ps))))
		exit(1);
	chk_inp(ac, av, ps) ? 0 : put_error();
	ps->out_en = 1;
	if (!(chk_sort(ps)))
		exit(0);
	chunk = ps->a_c / ((ps->a_c / 100 + 4) + 1);
	chunk = chunk == 0 ? 1 : chunk;
	mv_a(ps, chunk);
	while (ps->b_c)
	{
		smart_rt(ps, find_max(ps, 'b'), 1, 'b');
		pa(ps);
	}
	exit(0);
}
