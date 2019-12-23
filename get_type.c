/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:09:17 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 19:21:41 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//void	ft_char(va_list *args, t_p *p)
//{
//	char	c;
//
//	c = va_arg(*args, int);
//	p->param = ft_strnew(1);
//	if ((c == '\0' || c == 0))
//	{
//		p->res++;
//		p->b_0 = true;
//	}
//	else
//		p->param[0] = c;
//}

// void	ft_str(va_list *args, t_p *p)
// {
// 	char	*str;

// 	str = va_arg(*args, char *);
// 	p->param = (str ? str : "(null)");
// }

// void	ft_nbr(va_list *args, t_p *p)
// {
// 	int		num;

// 	num = va_arg(*args, int);//free str car itoa malloc
	// p->param = ft_itoa(num);
// 	//free(str);
// 	// str = NULL;
// 	//  free(str);

// }

void	ft_ui(va_list *args, t_p *p)
{
	long		n;
	long long	i;

	n = va_arg(*args, int);
	i = 0;
	if (n >= 0)
		p->param = ft_itoa(n);
	else
	{
		i = 4294967295 + n + 1;
		p->param = ft_itoa(i);
	}
}

void	ft_pc(t_p *p)
{
	int		v;
	int		j;
	int		res;
	char	*str;

	v = 0;
	while (p->src[p->i + v] == '%')
		v++;
	res = (v + 1) / 2;
	str = ft_strnew(res);
	j = 0;
	while (j < res)
	{
		str[j] = '%';
		j++;
	}
	p->param = str;
	p->i = p->i + v - 1;
}
