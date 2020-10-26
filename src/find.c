/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:18:26 by k3                #+#    #+#             */
/*   Updated: 2020/10/20 19:18:46 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		find_small(t_ps *ps, char c)
{
	int	*arr;
	int	arr_c;
	int	tmp;
	int	i;

	arr = c == 'a' ? ps->a : ps->b;
	arr_c = c == 'a' ? ps->a_c : ps->b_c;
	i = 0;
	tmp = arr[arr_c - 1];
	while (i < arr_c)
	{
		if (tmp > arr[i])
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
	tmp = arr[arr_c - 1];
	while (i < arr_c)
	{
		if (tmp < arr[i])
			tmp = arr[i];
		i++;
	}
	return (tmp);
}
