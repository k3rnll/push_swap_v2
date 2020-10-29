/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:48:45 by k3                #+#    #+#             */
/*   Updated: 2020/10/23 21:48:58 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_ps *ps)
{
	int	tmp;

	tmp = ps->a[0];
	ps->a[0] = ps->a[1];
	ps->a[1] = tmp;
	ps->out_en ? write(1, "sa\n", 3) : 0;
}

void	sb(t_ps *ps)
{
	int	tmp;

	tmp = ps->b[0];
	ps->b[0] = ps->b[1];
	ps->b[1] = tmp;
	ps->out_en ? write(1, "sb\n", 3) : 0;
}

void	ss(t_ps *ps)
{
	int	tmp;

	tmp = ps->out_en;
	ps->out_en = 0;
	sa(ps);
	sb(ps);
	ps->out_en = tmp;
	ps->out_en ? write(1, "ss\n", 3) : 0;
}
