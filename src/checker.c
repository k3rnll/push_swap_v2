/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:40:49 by k3                #+#    #+#             */
/*   Updated: 2020/10/24 15:47:12 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move(char *buf, t_ps *ps)
{
	if (ft_strequ(buf, "ra"))
		ra(ps);
	else if (ft_strequ(buf, "rb"))
		rb(ps);
	else if (ft_strequ(buf, "rra"))
		rra(ps);
	else if (ft_strequ(buf, "rrb"))
		rrb(ps);
	else if (ft_strequ(buf, "rrr"))
		rrr(ps);
	else if (ft_strequ(buf, "pa"))
		pa(ps);
	else if (ft_strequ(buf, "pb"))
		pb(ps);
	else if (ft_strequ(buf, "sa"))
		sa(ps);
	else if (*buf == '\0' || *buf == '\n')
		*buf = 0;
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	ft_memset(buf, 0, 6);
}

void	catch(void)
{
	char	c;
	int		i;

	i = 0;
	while (read(0, &c, 1))
		i++;
	put_error();
}

int		main(int ac, char **av)
{
	t_ps	*ps;
	char	buf[6];
	int		i;

	if (ac < 2)
		exit(0);
	if (!(ps = (t_ps *)malloc(sizeof(*ps))))
		exit(1);
	!chk_inp(ac, av, ps) ? catch() : 0;
	*buf = 0;
	ps->out_en = 0;
	i = 0;
	while (read(0, buf + i, 1))
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			move(buf, ps);
		}
		i = buf[i] != '\0' && i < 5 ? i + 1 : 0;
	}
	move(buf, ps);
	ft_strchr(buf, '\n') ? 0 : write(1, "\n", 1);
	chk_sort(ps) || ps->b_c ? write(1, "KO\n", 3) : write(1, "OK\n", 3);
	exit(0);
}
