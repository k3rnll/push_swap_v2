/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:11:44 by k3                #+#    #+#             */
/*   Updated: 2020/10/29 21:47:11 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	btoa(t_ps *ps)
{
	while (ps->b_c)
	{
		if (find_max(ps, 'b') > find_max(ps, 'a'))
		{
			smart_rt(ps, find_small(ps, 'a'), 0, 'a');
			smart_rt(ps, find_max(ps, 'b'), 0, 'b');
			pa(ps);
		}
		else
		{
			smart_rt(ps, find_max(ps, 'b'), 0, 'b');
			smart_rt(ps, find_next(ps, ps->b[0], 'a'), 0, 'a');
			pa(ps);
		}
	}
}

int		atob(t_ps *ps, int chunk)
{
	int	i;
	int	min;

	min = find_small(ps, 'a');
	while (ps->a_c - ps->s_c)
	{
		i = 0;
		while (ps->a_c - ps->s_c && i < chunk)
		{
			if (ps->a_c < 4 && chunk == 1)
			{
				sort_3(ps);
				return (0);
			}
			if (smart_rt(ps, min, chunk, 'a'))
			{
				smart_rt(ps, min, chunk / 2, 'b');
				pb(ps);
			}
			else
				i++;
		}
		min = find_small(ps, 'a');
	}
	return (0);
}

int		init_s(t_ps *ps)
{
	int	i;

	i = 0;
	ps->s[0] = find_small(ps, 'a');
	ps->s_c = 1;
	while (ps->a[i] != ps->s[0])
		i++;
	return (i);
}

void	parse_a(t_ps *ps)
{
	int	i;
	int	k;
	int	l;
	int j;

	k = 0;
	l = 0;
	i = init_s(ps);
	while (l < ps->a_c)
	{
		j = 1;
		while (j < 15)
		{
			if (ps->a[i] > ps->s[k] && ps->a[i] < ps->s[k] + j)
			{
				k++;
				ps->s[k] = ps->a[i];
				break ;
			}
			j++;
		}
		i = i < ps->a_c - 1 ? i + 1 : 0;
		l++;
	}
	ps->s_c = k + 1;
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
	parse_a(ps);
	atob(ps, chunk);
	ps->s_c = 0;
	btoa(ps);
	smart_rt(ps, find_small(ps, 'a'), 0, 'a');
	exit(0);
}
