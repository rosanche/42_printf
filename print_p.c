/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:27:33 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:28:43 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_p(va_list *args, t_p *p)
{
	unsigned long	num;
	int				d;

	d = 0;
	num = va_arg(*args, unsigned long);
	if (p->precision > p->width)
		d = 1;
	else if (p->precision == 0)
		d = -1;
	p->width -= (((p->precision > (int)ft_size_x((long long)num)) || num == 0)
	&& p->precision != -1) ? p->precision : (int)ft_size_x((long long)num);
	p->width -= 2;
	if (p->precision != -1)
		p->precision = p->precision > (int)ft_size_x((long long)num) ?
		p->precision - (int)ft_size_x((long long)num) : 0;
	p->moins ? print_smth('0', p->precision, p) : width_n_precision(p, d);
	ft_putstr_fd("0x", 1);
	p->res += 2;
	if (d != -1)
		ft_putnbr_x(num, 1, p);
	if (p->moins)
		width_n_precision(p, d);
}
