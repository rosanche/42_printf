/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:09:38 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 14:09:40 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_p		*init_p(const char *src)
{
	t_p *p;

	if (!(p = (t_p *)malloc(sizeof(t_p))))
		return (NULL);
	p->i = 0;
	p->src = (char *)src;
	p->res = 0;
	p->param = NULL;
	p->zero = false;
	p->moins = false;
	p->width = 0;
	p->precision = -1;
	p->etoile = false;
	p->pointetoile = false;
	p->strprecision = NULL;
	p->strwidth = NULL;
	p->nbrn = false;
	p->basex = "0123456789abcdef\0";
	p->basexx = "0123456789ABCDEF\0";
	p->count = 0;
	p->b_0 = false;
	p->params = "cspdiuxX%\0";
	return (p);
}

void	*init_f(t_p *p)
{
	p->zero = false;
	p->moins = false;
	p->width = 0;
	p->precision = -1;
	p->etoile = false;
	p->pointetoile = false;
	p->strprecision = NULL;
	p->strwidth = NULL;
	p->nbrn = false;
	p->count = 0;
	p->nb_param = -1;
	return (p);
}
