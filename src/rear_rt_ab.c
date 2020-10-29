/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rear_rt_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:55:14 by k3                #+#    #+#             */
/*   Updated: 2020/10/27 20:55:14 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_ps *ps)
{
	int	tmp;
	int	i;

	i = ps->a_c - 1;
	tmp = ps->a[i];
	while (i)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}
	ps->a[0] = tmp;
	ps->out_en ? write(1, "rra\n", 4) : 0;
}

void	rrb(t_ps *ps)
{
	int	tmp;
	int	i;

	if (ps->b_c > 1)
	{
		i = ps->b_c - 1;
		tmp = ps->b[i];
		while (i)
		{
			ps->b[i] = ps->b[i - 1];
			i--;
		}
		ps->b[0] = tmp;
		ps->out_en ? write(1, "rrb\n", 4) : 0;
	}
}

void	rrr(t_ps *ps)
{
	int	tmp;

	tmp = ps->out_en;
	ps->out_en = 0;
	rra(ps);
	rrb(ps);
	ps->out_en = tmp;
	ps->out_en ? write(1, "rrr\n", 4) : 0;
}
