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
    int nbr;

    nbr = va_arg(*list, int);
    //ft_putnbr(nbr);
    print->params = transformnbr(nbr);
    //return (transformnbr(nbr));
}

void    get_str(va_list *list, t_print *print)
{
    char *str;

    str = va_arg(*list, char *);
    str = ft_strnew(ft_strlen(str));
    // str = result;
    print->int_return += ft_strlen(str);
    print->params = str;
    //printf("\nstr:%s\n", print->params = str);
    //ft_putstr(str);
    //return (str);
}

void    get_Xhexa(va_list *list, t_print *print)
{
    int nbr;
    int pos;
    char tab[16]= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E' };
    char *str;
    int i;

    nbr = va_arg(*list, int);
    pos = nbr;
    i = 0;
    while (pos > 0)
    {
        i++;
        pos /= 16;
    }
    // if (!(str = (char *)malloc(sizeof(char) * i + 1)))
    //     return (-1);
    str = ft_strnew(i + 1);
    i = 0;
    while (nbr > 0)
    {
        nbr %= 16;
        str[i] = tab[nbr - 1];
        nbr /= 16;
        i++;
    }
    print->int_return += ft_strlen(str);
    print->params = str;
    //ft_putstr(str);
    //return (str);
}

void    get_xhexa(va_list *list, t_print *print)
{
    int nbr;
    int pos;
    char tab[16]= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    char *str;
    int i;

    nbr = va_arg(*list, int);
    pos = nbr;
    i = 0;
    while (pos > 0)
    {
        i++;
        pos /= 16;
    }
    // if (!(str = (char *)malloc(sizeof(char) * i + 1)))
    //     return (-1);
    str = ft_strnew(i + 1);
    i = 0;
    while (nbr > 0)
    {
        nbr %= 16;
        str[i] = tab[nbr - 1];
        nbr /= 16;
        i++;
    }
    print->int_return += ft_strlen(str);
    print->params = str;
    //ft_putstr(str);
    //return (str);
}

char    *get_unsigned(va_list *list, t_print *print)
{
    int nbr;

    nbr = va_arg(*list, int);
    return("Bijour");
}