/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:24:17 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 14:09:48 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
	// return (0);
}

// void	ft_fillflags(t_p *p)
// {
// 	if (p->nb_param == 0)
// 		ft_01(p);
// 	if (p->nb_param == 2)
// 		ft_02(p, p->nb_param);
// 	else if (p->nb_param >= 3 && p->nb_param <= 8)
// 		ft_03(p, p->nb_param);
// 	else if (p->nb_param == 1)
// 	{
// 		fill_param(p, p->nb_param, args);
// 		p->width -= (p->precision < (int)ft_strlen(p->param)
// 		&& p->precision != -1 ? p->precision : ft_strlen(p->param));
// 		ft_diuxx(p, p->nb_param);
// 		if (p->precision < (int)ft_strlen(p->param) && p->precision != -1)
// 			p->param = ft_substr(p->param, 0, p->precision);
// 	}
// }

void	ft_fillp(t_p *p)
{
	if (p->moins)
	{
		p->param = ft_strjoin(p->strprecision, p->param);
		if (p->nbrn)
			p->param = ft_strjoin("-", p->param);
		p->param = ft_strjoin(p->param, p->strwidth);
	}
	else
	{
		p->strwidth = ft_strjoin(p->strwidth, p->strprecision);
		p->param = ft_strjoin(p->strwidth, p->param);
	}
	// free(p->strwidth);
	// free(p->strprecision);
}

void	ft_fill_flag_and_join(t_p *p, va_list *args)
{
	// ft_fillflags(p);
	if (p->nb_param == 2)
		ft_fillp(p);
	else
	{
		fill_param(p, args);
		// if (p->moins)
		// {
		// 	// p->param = ft_strjoin(p->strprecision, p->param);
		// 	if (p->nbrn)
		// 		// p->param = ft_strjoin("-", p->param);
		// 	fill_param(p, args);
		// 	//p->param = ft_strjoin(p->param, p->strwidth);
		// }
		// else
		// {
		// 	if (p->nbrn)
		// 		p->strwidth = (p->zero && p->precision == -1 ?
		// 	ft_strjoin("-", p->strwidth) : ft_strjoin(p->strwidth, "-"));
			// fill_param(p, args);
			//p->strwidth = ft_strjoin(p->strwidth, p->strprecision);
			// p->param = ft_strjoin(p->strwidth, p->param); //free le param car il prend de la memoire
		// }
	}
	//free(p->strwidth);
	//free(p->strprecision);
}

void	ft_print(t_p *p, va_list *args)
{
	//fill_param(p, nb_param, args);
	// if (p->precision >= 0 || p->width > 0 || p->etoile)
	// 	ft_fill_flag_and_join(p, nb_param);
	// p->res += ft_strlen(p->param);
	if (p->b_0 && p->moins)
		ft_putchar_fd(0, 1);
	// if (p->precision >= 0 || p->width > 0 || p->etoile)
	ft_fill_flag_and_join(p, args); //voir apres
	p->res += ft_strlen(p->param);
	if (p->b_0 && !p->moins)
		ft_putchar_fd(0, 1);
}

int		ft_printf(const char *src, ...)
{
	va_list	args;
	t_p		*p;
	// int		nb_param;

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
		// free(p->param);
		// p->param = NULL;
	}
	// ft_strdel(&(p->param));
	return (p->res);
}
