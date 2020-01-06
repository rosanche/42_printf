/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:38:36 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:41:26 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putnbr_xx(unsigned long n, int fd, t_p *p)
{
	unsigned long nb;

	nb = n;
	if (n < 0)
		nb = -n;
	if (nb >= 16)
		ft_putnbr_xx(nb / 16, fd, p);
	ft_putchar_fd(p->basexx[nb % 16], fd);
	p->res++;
}

void		ft_xx(va_list *args, t_p *p)
{
	unsigned long		num;
	int					d;

	d = 0;
	num = va_arg(*args, unsigned long);
	if (p->precision > p->width)
		d = 1;
	else if (p->precision == 0 && num == 0)
		d = -1;
	p->width -= (((p->precision > (int)ft_size_x((long long)num)) || num == 0)
	&& p->precision != -1) ? p->precision : (int)ft_size_x((long long)num);
	if (p->precision != -1)
		p->precision = p->precision > (int)ft_size_x((long long)num) ?
		p->precision - (int)ft_size_x((long long)num) : 0;
	p->moins ? print_smth('0', p->precision, p) : width_n_precision(p, d);
	if (d != -1)
		ft_putnbr_xx(num, 1, p);
	if (p->moins)
		width_n_precision(p, d);
}
