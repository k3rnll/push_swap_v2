/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:09:08 by k3                #+#    #+#             */
/*   Updated: 2020/10/26 13:41:30 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_stack(t_ps *ps, int ac)
{
	int	i;

	if (!(ps->a = (int*)malloc((ac - 1) * sizeof(int))) ||
		!(ps->b = (int*)malloc((ac - 1) * sizeof(int))))
		exit(0);
	i = 0;
	while (i < ac - 1)
	{
		ps->a[i] = 0;
		ps->b[i] = 0;
		i++;
	}
	ps->b_c = 0;
}

int		chk_sort(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->a_c - 1)
	{
		if (ps->a[i] > ps->a[i + 1])
			return (ps->a_c - 1 - i);
		i++;
	}
	return (0);
}

void	sort_3(t_ps *ps)
{
	if (chk_sort(ps) && ps->a_c == 3)
	{
		if (ps->a[0] > ps->a[1] && ps->a[0] < ps->a[2])
			sa(ps);
		else if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2] &&
			ps->a[1] > ps->a[2])
		{
			sa(ps);
			rra(ps);
		}
		else if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
			ra(ps);
		else if (ps->a[0] < ps->a[1] && ps->a[0] < ps->a[2])
		{
			sa(ps);
			ra(ps);
		}
		else
			rra(ps);
	}
	else
		chk_sort(ps) ? sa(ps) : 0;
}
