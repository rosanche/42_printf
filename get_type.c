#include "ft_printf.h"

void    get_char(va_list *list, t_print *print)
{
    char c;

    //if (!(str = (char *)malloc(sizeof(char))))
      //  return (NULL);
    c = va_arg(*list, int);
    //write(1, &c, 1);
    print->int_return += 1;
    print->params[0] = c;
    //return (str);
}

void    get_int(va_list *list, t_print *print)
{
    int num;

	num = va_arg(*list, int);
	print->params = ft_itoan(num);
    print->int_return += ft_strlen(print->params);
    //ft_putnbr(nbr);
    //print->params = transformnbr(nbr);
    //return (transformnbr(nbr));
}

void    get_str(va_list *list, t_print *print)
{
    char *str;
    char *param;

    str = va_arg(*list, char *);
	if (ft_strlen(str) >= print->flags->precision && print->flags->precision != -1)
	{
		param = (char *)malloc(sizeof(char) * print->flags->precision + 1);
		ft_strncpy(param, str, print->flags->precision);
	}
	else
	{
		param = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		param = str;
	}
    print->int_return += ft_strlen(param);
    print->params = param;
	//free(param);
    //return (str);
}

void    get_Xhexa(va_list *list, t_print *print)
{
    unsigned long		num;
	char base[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
	, 'A', 'B', 'C', 'D', 'E', 'F', 0};
	char resultat[9] = {'0', '0', '0', '0', '0', '0', '0', '0', 0};
	int i;
	int rest;

	i = 0;
	num = va_arg(*list, unsigned long);
	while (num / 16 != 0)
	{
		rest = num % 16;
		resultat[i] = base[rest];
		num = num / 16;
		i++;
	}
	rest = num % 16;
	resultat[i] = base[rest];
	rest = i;
	print->params = resultat;
    print->int_return += rest + 1;
}

void    get_xhexa(va_list *list, t_print *print)
{
    unsigned long		num;
	char base[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
	, 'a', 'b', 'c', 'd', 'e', 'f', 0};
	char resultat[9] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', 0};
	int i;
	int rest;

	i = 0;
	rest = 0;
	num = va_arg(*list, unsigned long);
	//printf("\nnum: %lu\n", num);
	while (num / 16 != 0)
	{
		printf("\nnum: %d\n", rest);
		rest = num % 16;
		printf("\nnum: %d\n", rest);
		resultat[i] = base[rest];
		num = num / 16;
		i++;
	}
	rest = num % 16;
	//printf("\nrest: %d\n", rest);
	resultat[i] = base[rest];
	//printf("\nresult: %c\n", resultat[i]);
	rest = i;
	/*while (i > 0)
	{
		printf("\nresult2: %c\n", resultat[i]);
		print->params[i] = resultat[i];
		i--;
	}*/
	print->params = resultat;
	printf("\nparam: %s\n", print->params);
	printf("\nparamnbr: %d\n", ft_strlen(print->params));
	//print->params[i] = resultat[i];
	//printf("\nparam: %s\n", print->params);
}

void   get_unsigned(va_list *list, t_print *print)
{
    long		n;
	long long	i;

	n = va_arg(*list, int);
	i = 0;
	if (n < -2147483647 || n > 2147483647)
		print->params = ft_itoan(-1);
	else if (n >= 0)
		print->params = ft_itoan(n);
	else
	{
		i = 4294967295 + n + 1;
		print->params = ft_itoan(i);
    }
    print->int_return += ft_strlen(print->params);
}