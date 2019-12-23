/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:18:38 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 18:10:03 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_xx(va_list *args, t_p *p)
{
	unsigned long	num;
	char			*str;
	int				i;
	int				rest;
	char			*resultat;

	i = 0;
	rest = 0;
	num = va_arg(*args, unsigned long);
	resultat = ft_strnew(8);
	while (num / 16 != 0)
	{
		rest = num % 16;
		resultat[i] = p->basexx[rest];
		num = num / 16;
		i++;
	}
	rest = num % 16;
	resultat[i] = p->basexx[rest];
	str = ft_strnew(i);
	rest = 0;
	while (i >= 0)
		str[rest++] = resultat[i--];
	p->param = str;
}

void		ft_x(va_list *args, t_p *p)
{
	unsigned long		num;
	char				*str;
	int					i;
	int					rest;
	char				*resultat;

	i = 0;
	rest = 0;
	num = va_arg(*args, unsigned long);
	resultat = ft_strnew(8);
	while (num / 16 != 0)
	{
		rest = num % 16;
		resultat[i] = p->basex[rest];
		num = num / 16;
		i++;
	}
	rest = num % 16;
	resultat[i] = p->basex[rest];
	str = ft_strnew(i);
	rest = 0;
	while (i >= 0)
		str[rest++] = resultat[i--];
	p->param = str;
}

char		*ft_p_util(char *str, int i)
{
	str = ft_strnew(i + 2);
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

void		ft_p(va_list *args, t_p *p)
{
	unsigned long		num;
	char				*str;
	int					rest;
	char				*resultat;

	rest = 0;
	str = NULL;
	num = va_arg(*args, unsigned long);
	resultat = ft_strnew(8);
	while (num / 16 != 0)
	{
		rest = num % 16;
		resultat[p->count++] = p->basex[rest];
		num = num / 16;
	}
	rest = num % 16;
	resultat[p->count] = p->basex[rest];
	str = ft_p_util(str, p->count);
	rest = 0;
	if (p->count > 1 || (p->precision == -1))
	{
		while (p->count >= 0)
			str[rest++ + 2] = resultat[p->count--];
	}
	p->param = str;
}
