/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:18:26 by k3                #+#    #+#             */
/*   Updated: 2020/10/29 20:06:00 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		find_next(t_ps *ps, int inp, char c)
{
	int	*arr;
	int	arr_c;
	int	i;
	int tmp;

	arr = c == 'a' ? ps->a : ps->b;
	arr_c = c == 'a' ? ps->a_c : ps->b_c;
	tmp = 2147483647;
	i = 0;
	while (i < arr_c)
	{
		if (inp < arr[i] && arr[i] < tmp)
			tmp = arr[i];
		i++;
	}
	return (tmp);
}

int		find_small(t_ps *ps, char c)
{
	int	*arr;
	int	arr_c;
	int	tmp;
	int	i;

	arr = c == 'a' ? ps->a : ps->b;
	arr_c = c == 'a' ? ps->a_c : ps->b_c;
	i = 0;
	tmp = 2147483647;
	while (i < arr_c)
	{
		if (tmp > arr[i] && !(ch_match(ps, arr[i])))
			tmp = arr[i];
		i++;
	}
	return (tmp);
}

int		find_max(t_ps *ps, char c)
{
	int	*arr;
	int	arr_c;
	int	tmp;
	int	i;

	arr = c == 'a' ? ps->a : ps->b;
	arr_c = c == 'a' ? ps->a_c : ps->b_c;
	i = 0;
	tmp = -2147483648;
	while (i < arr_c)
	{
		if (tmp < arr[i])
			tmp = arr[i];
		i++;
	}
	return (tmp);
}
