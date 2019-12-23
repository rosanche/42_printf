/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:55:50 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 19:26:45 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_01(t_p *p)
{

	// printf("param3: %se\n", p->param);
	p->width -= ft_strlen(p->param);
	if (p->b_0)
		p->width--;
	if (p->width > 0)
		ft_memset(p);
}

void	ft_02(t_p *p, int nb_param)
{
	nb_param = -1; //inutile
	p->width -= ft_strlen(p->param);
	p->precision -= ft_strlen(p->param) - 2;
	ft_diuxx(p);
	// printf("param3: %se\n", p->param);
}

void	ft_03(t_p *p, int nb_param)
{
	// printf("cacacacaca");
	// printf("param3: %se\n", p->param);
	if (p->param[0] != '0' || p->precision != 0)
		p->width -= (p->precision > (int)ft_strlen(p->param) ?
		p->precision : ft_strlen(p->param));
	if (p->param[0] == '-' && (nb_param >= 3 && nb_param <= 4))
	{
		// printf("param3: %se\n", p->param);
		p->param = ft_memmove(p->param); //inutile car on afficherai pas le - directement et on le garde dans le bool
		// printf("param3: %se\n", p->param);
		p->nbrn = true;
		if (p->precision != -1 && !p->width)
			p->width--;
		else if (p->width && p->precision > (int)ft_strlen(p->param))
			p->width--;
	}
	p->precision = (p->precision - (int)ft_strlen(p->param) == -1 ?
	0 : p->precision);
	if (p->precision != -1)
	{
		p->param = !p->precision && p->param[0] == '0' ? NULL : p->param;
		p->precision -= ft_strlen(p->param);
	}
	// printf("param3: %se\n", p->param);
	ft_diuxx(p);
	// printf("param3: %se\n", p->param);
}
