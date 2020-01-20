/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:34:52 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:35:04 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	ft_size_u(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n >= 0)
		return (ft_size(n));
	else 
	{
		i = 4294967295 + n + 1;
		return (ft_size(i));
	}
}

void	convert_u(unsigned int nb, t_p *p)
{
	long		n;
	unsigned int	i;

	n = nb;
	i = 0;
	if (n >= 0)
		ft_putnbr_u((unsigned int)n, 1, p);
	else
	{
		i = 4294967295 + n + 1;
		ft_putnbr_u(i, 1, p);
	}
}

void	ft_u_width(t_p *p, unsigned int num)
{
	if ((!p->moins) && (p->zero) && p->precision == -1
		&& p->width > p->precision && p->bprecision == false)
	{
		// print_smth('0', p->width, p);
		if (p->precision == -1)
			print_smth('0', p->width, p);
		else
			print_smth(' ', p->width, p);
		convert_u(num, p);
	}
	else if (p->moins)
	{
		print_smth('0', p->precision, p);
		convert_u(num, p);
		print_smth(' ', p->width, p);
	}
	else if (p->zero && p->width < p->precision && !p->bprecision)
	{
		p->width -= p->precision > 0 && p->nbrn ? 1 : 0;
		print_smth('0', p->width, p);
		if (p->precision != 0)
			print_smth('0', p->precision, p);
		if (num != 0 || p->precision != 0)
			convert_u(num, p);
	}
	else
	{
		p->width -= p->precision > 0 && p->nbrn ? 1 : 0;
		print_smth(' ', p->width, p);   //--> pb ici om devrait print des 0 pas des ' '
		if (p->precision != 0)
			print_smth('0', p->precision, p);
		if (num != 0 || p->precision != 0)
			convert_u(num, p);
	}
}

void	ft_u(t_p *p, unsigned int num)
{
	if (p->width >= 1)
		ft_u_width(p, num);
	else
	{
		p->precision = p->nbrn ? p->precision + 1 : p->precision;
		print_smth('0', p->precision, p);
		convert_u(num, p);
	}
}

void	ft_ui(va_list *args, t_p *p)
{
	unsigned int		num;

	num = va_arg(*args, int);
	p->width -= (p->precision > (int)ft_size_u(num))
	&& p->precision != -1 ? p->precision : (int)ft_size_u(num);
	if (p->precision > -1)
		p->bprecision = true;
	if ((int)ft_size_u(num) == 1 && p->precision == 0 && num == 0)
		p->width++;
	if (p->precision != 0)
		p->precision = p->precision > (int)ft_size_u(num) ?
		p->precision - (int)ft_size_u(num) : -1;
	if (p->moins && p->precision == -1)
	{
		print_smth('0', p->precision, p);
		ft_u(p, num);
	}
	else if (p->precision == 0 && p->width == 0 && num == 0)
		return ;
	else if (!(p->moins))
		ft_u(p, num);
	else if ((p->moins && p->precision > 0) || (p->precision == 0 && num != 0))
		ft_u(p, num);
	else if (p->precision == 0 && p->width > 0)
		print_smth(' ', p->width, p);
	else
		ft_u(p, num);
}
