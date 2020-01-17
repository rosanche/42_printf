/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:22:03 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/03 17:28:34 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_di_width_else(t_p *p, int num)
{
	if ((p->precision > 0 && p->nbrn) )
		p->width--;
	p->width -= (int)ft_size((long long)num) == 1 && p->precision == 0 
	&& p->width != 0 && num != 0 ? 1 : 0;
	print_smth(' ', p->width, p);
	if (p->precision != 0 || num != 0)
	{
		if (p->nbrn)
		{
			ft_putchar_fd('-', 1);
			if (!p->done && p->precision != 0)
				p->precision++;
		}
		print_smth('0', p->precision, p);
		ft_putnbr_fd(num, 1, p);
	}
}

void			ft_di_width(t_p *p, int num)
{
	if ((!p->moins) && (p->zero) && p->precision == -1
	&& p->width > p->precision && p->bprecision == false)
	{
		if (p->nbrn)
			ft_putchar_fd('-', 1);
		if (p->precision == -1)
			print_smth('0', p->width, p);
		else
			print_smth(' ', p->width, p);
		ft_putnbr_fd(num, 1, p);
	}
	else if (p->moins)
	{
		if (p->nbrn)
		{
			ft_putchar_fd('-', 1);
			p->precision += p->precision > 0 ? 1 : 0;
			p->width -= p->precision > 0 ? 1 : 0;
		}
		 if (p->moins && p->precision == (int)ft_size(num) - 1 && p->nbrn)
		 	p->precision--; 
		print_smth('0', p->precision, p);
		if (!(num == 0 && p->precision == 0 && p->moins))
			ft_putnbr_fd(num, 1, p);           
		print_smth(' ', p->width, p);
	}
	else
		ft_di_width_else(p, num);
}

void			ft_di(t_p *p, int num)
{
	if (p->width >= 1)
		ft_di_width(p, num);
	else
	{
		if (p->nbrn)
			ft_putchar_fd('-', 1);
		if (p->precision != 0 && !p->done)
				p->precision = p->nbrn ? p->precision + 1 : p->precision;
		print_smth('0', p->precision, p);
		ft_putnbr_fd(num, 1, p);
	}
}

void			init_prec_width(t_p *p, int num)
{
	p->nbrn = num < 0 ? true : false;
	p->res += num < 0 ? 1 : 0;
	p->width -= (p->precision > (int)ft_size((long long)num))
	&& p->precision != -1 ? p->precision : (int)ft_size((long long)num);
	p->bprecision = p->precision > -1 ? true : false;
	p->width += (int)ft_size((long long)num) == 1 && p->precision == 0 
	&& ((p->width != 0 && !p->moins) || num == 0) ? 1 : 0;
}

void			ft_nbr(va_list *args, t_p *p)
{
	int		num;
	num = va_arg(*args, int);
	init_prec_width(p, num);
	if (p->precision != 0)
	{	
		if (p->precision == (int)ft_size((long long)num) && p->nbrn)
		{	
			p->precision = 1;
			p->done = true;
		}
		else 
			p->precision = p->precision > (int)ft_size((long long)num) ?
			p->precision - (int)ft_size((long long)num) : -1;
	}
	if (p->precision == 0 && p->width == 0 && num == 0)
		return ;
	else if (p->moins && (p->precision == -1 || p->precision == 0))
	{
		print_smth('0', p->precision, p);
		ft_di(p, num);
	}
	else if (!(p->moins))
		ft_di(p, num); 
	else if (p->moins && p->precision > 0)
		ft_di(p, num);
	else if (p->precision == 0 && p->width > 0)
	{
		print_smth(' ', p->width, p);
		if (num != 0)
			ft_di(p, num);
	}
}
