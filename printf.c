/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:45:07 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/06 13:02:34 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print(t_p *p, va_list *args)
{
	if (p->b_0 && p->moins)
		ft_putchar_fd(0, 1);
	fill_param(p, args);
	if (p->b_0 && !p->moins)
		ft_putchar_fd(0, 1);
}

int		ft_printf(const char *src, ...)
{
	va_list	args;
	t_p		*p;

	va_start(args, src);
	p = init_p(src);
	if (ft_checkerror(p))
		return (-1);
	while (p->src[p->i])
	{
		init_f(p);
		if (p->i != 0 && p->src[p->i - 1] == '%' && p->src[p->i - 2] != '%')
		{
			p->nb_param = find_flags_and_nbparam(p, &args);
			ft_print(p, &args);
		}
		else if (p->src[p->i] != '%')
		{
			write(1, &p->src[p->i], 1);
			p->res++;
		}
		p->i++;
	}
	free(p);
	return (p->res);
}
