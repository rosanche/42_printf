/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:35:46 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:37:59 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	ft_size_x(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n / 16 > 0)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}

void			width_n_precision(t_p *p, int d)
{
	if (p->width >= 1)
	{
		if ((p->zero) && p->precision != 0 && (d == 1 || p->precision == -1))
			print_smth('0', p->width, p);
		else
			print_smth(' ', p->width, p);
	}
	else
	{
		if (p->nbrn)
			ft_putchar_fd('-', 1);
	}
	if (p->precision && !p->moins)
		print_smth('0', p->precision, p);
}

void			ft_putnbr_x(unsigned int n, int fd, t_p *p)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
		nb = -n;
	if (nb >= 16)
		ft_putnbr_x(nb / 16, fd, p);
	ft_putchar_fd(p->basex[nb % 16], fd);
	p->res++;
}

void			ft_x(va_list *args, t_p *p)
{
	unsigned int	num;
	int				d;

	d = 0;
	num = va_arg(*args, unsigned int);
	if (p->precision > p->width)
		d = 1;
	else if (p->precision == 0 && num == 0)
		d = -1;
	p->width -= (((p->precision > (int)ft_size_x((unsigned int)num)) || num == 0)
	&& p->precision != -1) ? p->precision : (int)ft_size_x((unsigned int)num);
	if (p->precision != -1)
		p->precision = p->precision > (int)ft_size_x((unsigned int)num) ?
		p->precision - (int)ft_size_x((unsigned int)num) : 0;
	p->moins ? print_smth('0', p->precision, p) : width_n_precision(p, d);
	if (d != -1)
		ft_putnbr_x(num, 1, p);
	if (p->moins)
		width_n_precision(p, d);
}
