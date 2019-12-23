/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:27:54 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 18:42:52 by aguenel          ###   ########.fr       */
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
	if (!(str = (char *)malloc(sizeof(char) * v + 1))) //free str avant de le renvoyer
		return (-1);
	v = 0;
	while (ft_isdigit((int)p->src[p->i + v]))
	{
		str[v] = p->src[p->i + v];
		v++;
	}
	p->i += v - 1;
	v = ft_atoi(str);
	// free(str);
	// str = NULL;
	// ft_strdel(&str);
	//ft_putstr_fd(ft_itoa(v), 1);
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
	{
			p->width = guess_width(p);	
	}
	else if (p->src[p->i] == '*')
	{
		p->width = va_arg(*args, int);
		if (p->width < 0)
		{
			p->width *= -1;
			p->moins = true;
		}
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

void	fill_param(t_p *p,va_list *args)
{
	void	(*tabFunc[9])(va_list *, t_p *) = {ft_char, ft_str, ft_p,
	ft_nbr, ft_nbr, ft_ui, ft_x, ft_xx};

	if (p->nb_param >= 0 && p->nb_param < 8)
		(*tabFunc[p->nb_param])(args, p);
	else if (p->nb_param == 8)
		ft_pc(p);
}

// void	ft_diuxx(t_p *p, int nb_param)
// {
// 	if (p->precision >= 1 && nb_param != 1)
// 		ft_memsetpre(p);
// 	//  printf("param34: %se\n", p->param);
// 	if (p->width >= 1)
// 	{
// 		if ((!p->moins) && (p->zero) && p->precision == -1
// 			&& p->width > p->precision)
// 		{
// 			ft_memsetzero(p);
// 		}
// 		else
// 			ft_memset(p);
// 	}
// }
