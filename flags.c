#include "ft_printf.h"
#include "libft/libft.h"


void    print_width(t_flags *t_flags, bool boolean, t_print *print)
{
    int i;

    i = 0;
    printf("\nparam005: %s\n", print->params);
    if (t_flags->width > 0)
    {
        if (boolean)
            while (i < t_flags->width)
            {
                ft_putchar('0');
                i++;
            }
        else
            while (i < t_flags->width)
            {
                ft_putchar(' ');
                i++;
                //printf("bonjour");
            }
    }
}

int     guess_width(t_print *print)
{
    char *str;
    int v;

    v = 0;
    while (ft_isdigit((int)print->str[print->i + v]))
        v++;
    if (!(str = (char *)malloc(sizeof(char) * v + 1)))
        return (-1);
    v = 0;
    while (ft_isdigit((int)print->str[print->i + v]))
    {
        str[v] = print->str[print->i + v];
        v++;
    }
    print->i += v - 1;
    return (ft_atoi(str));
}

void    print_precision(t_flags *precision)
{
    int i;

    i = 0;
    if (precision->precision >= 0)
        while (i < precision->precision)
        {
            ft_putchar('0');
            i++;
        }
}

void    find_flags(t_flags *flags, t_print *print)
{
    if (print->str[print->i] == '-')
        flags->moins = true;
    else if (print->str[print->i]  == '.')
    {
        print->i++;
        flags->precision = guess_width(print);
    }
    else if (print->str[print->i] == '0')
        flags->zero = true;
    else if (print->str[print->i] >= '0' && print->str[print->i] <= '9')
        flags->width = guess_width(print);
    else if (print->str[print->i]  == '*')
        flags->etoile = true;
}