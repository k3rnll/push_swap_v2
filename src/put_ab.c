/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:38:30 by k3                #+#    #+#             */
/*   Updated: 2020/10/23 21:38:44 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_ps *ps)
{
	down_stack(ps, ps->a);
	ps->a_c += 1;
	ps->a[0] = ps->b[0];
	up_stack(ps, ps->b);
	ps->b_c -= 1;
	ps->out_en ? write(1, "pa\n", 3) : 0;
}

void	pb(t_ps *ps)
{
	down_stack(ps, ps->b);
	ps->b_c += 1;
	ps->b[0] = ps->a[0];
	up_stack(ps, ps->a);
	ps->a_c -= 1;
	ps->out_en ? write(1, "pb\n", 3) : 0;
}
