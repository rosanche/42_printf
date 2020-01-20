/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:45:44 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:46:06 by rosanche         ###   ########.fr       */
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
	p->zero = false;
	p->moins = false;
	p->lettre = false;
	p->width = 0;
	p->precision = -1;
	p->etoile = false;
	p->pointetoile = false;
	p->nbrn = false;
	p->basex = "0123456789abcdef\0";
	p->basexx = "0123456789ABCDEF\0";
	p->count = 0;
	p->b_0 = false;
	p->bprecision = false;
	p->params = "cspdiuxX%\0";
	p->done = false;
	p->lettre = false;
	p->done = false;
	p->pair = false;
	return (p);
}

void	*init_f(t_p *p)
{
	p->zero = false;
	p->moins = false;
	p->width = 0;
	p->precision = -1;
	p->bprecision = false;
	p->etoile = false;
	p->pointetoile = false;
	p->nbrn = false;
	p->pair = false;
	p->count = 0;
	p->nb_param = -1;
	return (p);
}
