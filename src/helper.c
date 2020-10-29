/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:10:40 by k3                #+#    #+#             */
/*   Updated: 2020/10/27 21:17:10 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_numlen(long tmp)
{
	int	i;

	i = 0;
	if (tmp == 0)
		return (1);
	tmp = tmp < 0 ? tmp * -1 : tmp;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

int		ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (i);
}

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int		chk_double(t_ps *ps, int tmp, int i)
{
	if (i < 1)
		return (0);
	while (i-- > 0)
	{
		if (tmp == ps->a[i])
			return (1);
	}
	return (0);
}

int		chk_inp(int ac, char **av, t_ps *ps)
{
	int	i;
	int	len;
	int	tmp;

	clear_stack(ps, ac);
	i = 1;
	while (i < ac)
	{
		if (!(len = ft_isnumber(av[i])) && len > 11)
			return (0);
		tmp = ft_atoi(av[i]);
		if (len != ft_numlen(tmp) + (*av[i] == '-' || *av[i] == '+'))
			return (0);
		if (*av[i] != '-' && tmp < 0)
			return (0);
		if (*av[i] == '-' && tmp > 0)
			return (0);
		if (chk_double(ps, tmp, i - 1))
			return (0);
		ps->a[i - 1] = tmp;
		i++;
	}
	ps->a_c = ac - 1;
	return (1);
}
