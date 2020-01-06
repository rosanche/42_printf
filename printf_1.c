/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:43:34 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/03 15:35:04 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		guess_width(t_p *p)
{
	char	*str;
	int		v;

	v = 0;
	while (ft_isdigit((int)p->src[p->i + v]))
		v++;
	if (!(str = ft_strnewm(v + 1)))
		return (-1);
	v = 0;
	while (ft_isdigit((int)p->src[p->i + v]))
	{
		str[v] = p->src[p->i + v];
		v++;
	}
	p->i += v - 1;
	v = ft_atoi(str);
	free(str);
	str = NULL;
	return (v);
}

void	find_flags(t_p *p, va_list *args)
{
	if (p->src[p->i] == '-')
		p->moins = true;
	else if (p->src[p->i] == '.')
	{
		p->i++;
		if (p->src[p->i] == '*')
		{
			p->precision = va_arg(*args, int);
			if (p->precision < 0)
				p->precision = -1;
		}
		else
			p->precision = guess_width(p);
	}
	else if (p->src[p->i] == '0')
		p->zero = true;
	else if (ft_isdigit((int)p->src[p->i]))
		p->width = guess_width(p);
	else if (p->src[p->i] == '*')
	{
		p->width = va_arg(*args, int);
		p->moins = p->width < 0 ? true : p->moins;
		if (p->width < 0)
			p->width *= -1;
	}
}

int		find_flags_and_nbparam(t_p *p, va_list *args)
{
	int		j;
	int		res;

	res = -1;
	while (res == -1)
	{
		j = 0;
		while (p->params[j] != p->src[p->i] && p->params[j])
			j++;
		if (j >= 9)
		{
			find_flags(p, args);
			p->i++;
		}
		else
			res = j;
	}
	return (res);
}

void	fill_param(t_p *p, va_list *args)
{
	void	(*tabfunc[9])(va_list *, t_p *);

	tabfunc[0] = ft_char;
	tabfunc[1] = ft_str;
	tabfunc[2] = ft_p;
	tabfunc[3] = ft_nbr;
	tabfunc[4] = ft_nbr;
	tabfunc[5] = ft_ui;
	tabfunc[6] = ft_x;
	tabfunc[7] = ft_xx;
	if (p->nb_param >= 0 && p->nb_param < 8)
		(*tabfunc[p->nb_param])(args, p);
	else if (p->nb_param == 8)
		ft_percent(p);
}
