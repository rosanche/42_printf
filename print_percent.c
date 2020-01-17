/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:29:31 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:30:13 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_percent(t_p *p)
{
	int		v;
	int		j;

	v = 0;
	while (p->src[p->i + v] == '%' && p->src[p->i + v])
		v++;
	if (!(v % 2))
		p->i += v - 1;
	else
	{
		p->i += v;
		p->pair = true;
	}
	v = (v + 1) / 2;
	p->width--;
	j = -1;
	if (!p->moins)
		ft_diuxx(p);
	while (++j < v)
	{
		ft_putchar_fd('%', 1);
		p->res++;
	}
	if (p->moins)
		ft_diuxx(p);
	if (p->pair && p->src[p->i])
	{
		write(1, &p->src[p->i], 1);
		p->res++;
	}
}
