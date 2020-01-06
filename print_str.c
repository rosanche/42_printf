/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:24:09 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:25:56 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_smth(char c, int nb, t_p *p)
{
	int i;

	i = 0;
	while (i++ < nb)
	{
		write(1, &c, 1);
		p->res++;
	}
}

void	ft_diuxx(t_p *p)
{
	if (p->width >= 1)
	{
		if ((!p->moins) && (p->zero) && p->precision == -1
			&& p->width > p->precision)
		{
			if (p->nbrn)
				ft_putchar_fd('-', 1);
			print_smth('0', p->width, p);
		}
		else
			print_smth(' ', p->width, p);
	}
	else
	{
		if (p->nbrn)
			ft_putchar_fd('-', 1);
	}
}

void	ft_str(va_list *args, t_p *p)
{
	char	*str;

	str = va_arg(*args, char *);
	str = str ? str : "(null)";
	p->width -= (p->precision < (int)ft_strlen(str)
	&& p->precision != -1 ? p->precision : ft_strlen(str));
	if (p->moins)
	{
		p->precision < (int)ft_strlen(str) && p->precision != -1 ?
		ft_putnstr_fd(str, 1, p->precision) : ft_putstr_fd(str, 1);
		p->res += p->precision < (int)ft_strlen(str) && p->precision != -1 ?
		p->precision : ft_strlen(str);
		ft_diuxx(p);
	}
	else
	{
		ft_diuxx(p);
		p->precision < (int)ft_strlen(str) && p->precision != -1 ?
		ft_putnstr_fd(str, 1, p->precision) : ft_putstr_fd(str, 1);
		p->res += p->precision < (int)ft_strlen(str) && p->precision != -1 ?
		p->precision : ft_strlen(str);
	}
}
