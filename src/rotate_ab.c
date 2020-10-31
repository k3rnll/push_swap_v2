/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:43:06 by k3                #+#    #+#             */
/*   Updated: 2020/10/31 11:28:45 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_ps *ps)
{
	int	tmp;
	int	i;

	i = 0;
	if (ps->a_c)
	{
		tmp = ps->a[0];
		while (i < ps->a_c - 1)
		{
			ps->a[i] = ps->a[i + 1];
			i++;
		}
		ps->a[ps->a_c - 1] = tmp;
	}
	ps->out_en ? write(1, "ra\n", 3) : 0;
}

void	rb(t_ps *ps)
{
	int	tmp;
	int	i;

	i = 0;
	if (ps->b_c)
	{
		tmp = ps->b[0];
		while (i < ps->b_c - 1)
		{
			ps->b[i] = ps->b[i + 1];
			i++;
		}
		ps->b[ps->b_c - 1] = tmp;
	}
	ps->out_en ? write(1, "rb\n", 3) : 0;
}

void	rr(t_ps *ps)
{
	int	tmp;

	tmp = ps->out_en;
	ps->out_en = 0;
	ra(ps);
	rb(ps);
	ps->out_en = tmp;
	ps->out_en ? write(1, "rr\n", 3) : 0;
}
