/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:05:38 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/03 15:06:49 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_size(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

int				ft_atoi(const char *str)
{
	int		res;
	int		negative;

	negative = 1;
	res = 0;
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	str--;
	return ((int)res * negative);
}

void			ft_putnbr_fd(int n, int fd, t_p *p)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
		nb = -n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd, p);
	ft_putchar_fd(nb % 10 + '0', fd);
	p->res++;
}

void			ft_putnbr_u(unsigned int n, int fd, t_p *p)
{
	unsigned int nb;

	nb = n;
	if (n < 0 && n != 4294967295)
		nb = -n;
	if (nb >= 10)
		ft_putnbr_u(nb / 10, fd, p);
	ft_putchar_fd(nb % 10 + '0', fd);
	p->res++;
}
