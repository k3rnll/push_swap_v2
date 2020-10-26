/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:41:48 by k3                #+#    #+#             */
/*   Updated: 2020/10/24 15:14:02 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		smart_rt(t_ps *ps, int min, int chunk, char c)
{
	int		i;
	int		k;
	int		counter;
	int		*arr;

	arr = c == 'a' ? ps->a : ps->b;
	counter = c == 'a' ? ps->a_c : ps->b_c;
	i = 0;
	k = counter - 1;
	while (!(arr[i] >= min && arr[i] < min + chunk) && i < counter)
		i++;
	while (!(arr[k] >= min && arr[k] < min + chunk) && k >= 0)
		k--;
	if (i < counter || k >= 0)
	{
		if (i <= counter - 1 - k)
			while (i--)
				c == 'a' ? ra(ps) : rb(ps);
		else
			while (counter - k++)
				c == 'a' ? rra(ps) : rrb(ps);
		return (1);
	}
	return (0);
}
