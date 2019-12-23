/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:36:35 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 16:43:47 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	i = -1;
	while (s1[++i])
		r[i] = s1[i];
	j = -1;
	while (s2[++j])
		r[i + j] = s2[j];
	r[i + j] = '\0';
	return (r);
}

char			*ft_strnew(int size)
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

void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putstr_fd(char *s, int fd)
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

// unsigned int	ft_size(long long n)
// {
// 	int	i;

// 	i = 0;
// 	if (n < 0)
// 	{
// 		i++;
// 		n = -n;
// 	}
// 	while (n / 10 > 0)
// 	{
// 		n = n / 10;
// 		i++;
// 	}
// 	return (i + 1);
// }
