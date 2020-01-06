/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:44:08 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/03 15:34:19 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strnewm(int size)
{
	char	*s;
	int		i;

	i = 0;
	s = (char*)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	size;
	int	i;

	if (!s || !fd)
		return ;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		ft_putchar_fd(s[i], fd);
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

void	ft_putnstr_fd(char *s, int fd, int size)
{
	int	i;

	if (!s || !fd)
		return ;
	i = 0;
	while (i < size)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
