/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_dw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:49:32 by k3                #+#    #+#             */
/*   Updated: 2020/10/26 13:43:42 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	up_stack(t_ps *ps, int *arg)
{
	int	i;

	i = 0;
	while (i < ps->a_c + ps->b_c - 2)
	{
		arg[i] = arg[i + 1];
		i++;
	}
}

void	down_stack(t_ps *ps, int *arg)
{
	int	i;

	i = ps->a_c + ps->b_c - 1;
	while (i > 0)
	{
		arg[i] = arg[i - 1];
		i--;
	}
}
