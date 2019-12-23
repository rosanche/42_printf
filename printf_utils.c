/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:53:59 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 16:40:28 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_memset(t_p *p)
{
	int		i;

	p->strwidth = ft_strnew(p->width); //free strwidth apres ?ce que je fais deja?
	i = 0;
	while (i < p->width)
	{
		p->strwidth[i] = ' ';
		i++;
	}
}

void	ft_memsetzero(t_p *p)
{
	int		i;

	p->strwidth = ft_strnew(p->width);
	i = 0;
	while (i < p->width)
	{
		p->strwidth[i] = '0';
		i++;
	}
}

void	ft_memsetpre(t_p *p)
{
	int		i;

	// printf("param3456: %s\n", p->param);
	// ft_putstr_fd(p->param, 1);
	p->strprecision = ft_strnew(p->precision);
	// ft_putstr_fd(p->param, 1);
	//printf("param345: %se\n", p->param);
	i = 0;
	//printf("param34: %se\n", p->param);
	while (i < p->precision)
	{
		p->strprecision[i] = '0';
		i++;
	}
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
		size++;
	if (!(s2 = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
