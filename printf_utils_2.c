/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:38:25 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 16:45:40 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_itoa(long long n)
{
	char			*str;
	long long		i;
	int				j;

	if (n == 0)
		return (ft_strdup("0"));
	j = ft_size(n);
	if (!(str = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = n;
	str[j] = '\0';
	while (j--)
	{
		if (n < 0)
			n = -n;
		str[j] = (n % 10 + '0');
		n = n / 10;
	}
	if (i < 0)
		str[0] = '-';
	return (str);
}

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

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (!(ptr = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[start + i] && start < ft_strlen(s))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char			*ft_memmove(char *src)
{
	unsigned int		i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char*)src;
	while (ptr[++i])
		ptr[i - 1] = ptr[i];
	ptr[i - 1] = ptr[i];
	return ((char *)ptr);
}

int				ft_atoi(const char *str)
{
	int		res;
	int		negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return ((int)res * negative);
}
