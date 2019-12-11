#include "libft/libft.h"

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

char			*ft_itoan(long long n)
{
	char	*str;
	long long		i;
	int		j;

	if (n == 0)
		return (ft_strdup("0"));
//	if (n == -2147483648)
//		return (ft_strdup("-2147483648"));
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