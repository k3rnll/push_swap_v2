/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:40:49 by k3                #+#    #+#             */
/*   Updated: 2020/10/27 20:42:56 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	catch(void)
{
	char	c;
	int		i;

	i = 0;
	while (read(0, &c, 1))
		i++;
	put_error();
}

void	move(char *buf, t_ps *ps)
{
	if (ft_strequ(buf, "ra\n"))
		ra(ps);
	else if (ft_strequ(buf, "rb\n"))
		rb(ps);
	else if (ft_strequ(buf, "rr\n"))
		rr(ps);
	else if (ft_strequ(buf, "rra\n"))
		rra(ps);
	else if (ft_strequ(buf, "rrb\n"))
		rrb(ps);
	else if (ft_strequ(buf, "rrr\n"))
		rrr(ps);
	else if (ft_strequ(buf, "pa\n"))
		pa(ps);
	else if (ft_strequ(buf, "pb\n"))
		pb(ps);
	else if (ft_strequ(buf, "sa\n"))
		sa(ps);
	else if (ft_strequ(buf, "sb\n"))
		sb(ps);
	else if (ft_strequ(buf, "ss\n"))
		ss(ps);
	else
		catch();
	ft_memset(buf, 0, 6);
}

int		main(int ac, char **av)
{
	t_ps	*ps;
	char	*buf;
	int		i;

	if (ac < 2)
		exit(0);
	if (!(ps = (t_ps *)malloc(sizeof(*ps))))
		exit(1);
	!chk_inp(ac, av, ps) ? catch() : 0;
	buf = ft_strnew(6);
	ps->out_en = 0;
	i = 0;
	while (read(0, buf + i, 1))
	{
		if (buf[i] == '\n')
			move(buf, ps);
		i = buf[i] != '\0' && i < 5 ? i + 1 : 0;
	}
	*buf != '\n' ? write(1, "\n", 1) : 0;
	*buf ? put_error() : 0;
	chk_sort(ps) || ps->b_c ? write(1, "KO\n", 3) : write(1, "OK\n", 3);
	exit(0);
}
