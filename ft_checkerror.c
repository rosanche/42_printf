/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:45:54 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/02 20:46:02 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_checkerror(t_p *p)
{
	int		i;
	int		v;

	i = 0;
	while (p->src[i] && p->src[i] != '%')
		i++;
	if (i < (int)ft_strlen(p->src))
	{
		while (i < (int)ft_strlen(p->src))
		{
			v = 0;
			while (p->src[i + 1] != p->params[v] && p->params[v])
				v++;
			if (v < (int)ft_strlen(p->params))
				return (0);
			else
				i++;
		}
		return (1);
	}
	return (0);
}
