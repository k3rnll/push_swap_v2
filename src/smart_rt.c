/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:41:48 by k3                #+#    #+#             */
/*   Updated: 2020/10/29 20:28:52 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_ps *ps, int i, int k, char c)
{
	int len;

	len = c == 'a' ? ps->a_c : ps->b_c;
	if (i <= len - 1 - k)
		while (i--)
			c == 'a' ? ra(ps) : rb(ps);
	else
		while (len - k++)
			c == 'a' ? rra(ps) : rrb(ps);
}

int		smart_rt(t_ps *ps, int min, int chunk, char c)
{
	int		i;
	int		k;
	int		len;
	int		*arr;

	arr = c == 'a' ? ps->a : ps->b;
	len = c == 'a' ? ps->a_c : ps->b_c;
	i = 0;
	k = len == 0 ? 0 : len - 1;
	chunk = min + chunk < min ? 0 : chunk;
	while (i < len &&
		(ch_match(ps, arr[i]) || !(arr[i] >= min && arr[i] <= min + chunk)))
		i++;
	while (k >= 0 &&
		(ch_match(ps, arr[k]) || !(arr[k] >= min && arr[k] <= min + chunk)))
		k--;
	if (i < len || k >= 0)
	{
		rotate(ps, i, k, c);
		return (1);
	}
	return (0);
}
