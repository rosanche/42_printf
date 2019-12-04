

#include "ft_printf.h"
#include    "libft/libft.h"

char    *transformnbr(int n)
{
    char *str;
    int i;
	unsigned int nb;

	nb = n;
    i = 0;
    
	if (n < 0)
	{
		nb = -n;
        i++;
	}
    while (nb > 0)
    {
        i++;
        nb /= 10;
    }
    if (!(str = (char *)malloc(sizeof(char) * i + 1)))
        return (NULL);
    nb = n;
    i--;
    while (nb > 0)
    {
        str[i] = nb % 10 + '0';
        i--;
        nb /= 10;
    }
    if (n < 0)
        str[i] = '-';
	return (str);
}

int     find_param(char *params, t_print *print)
{
    int v;

    v = 0;
    print->start = print->i; 
    while (params[v] != print->str[print->i] && params[v])
        v++;
    if (ft_strlen(params) == v)
        return (-1);
    print->end = print->i;
    return (v);    
}

t_flags     *init_flags(void)
{
    t_flags *flags;

    if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
        return (NULL);
    flags->zero = false;
    flags->moins = false;
    flags->width = 0;
    flags->precision = -1;
    flags->etoile = false;
    return (flags);
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

t_print *init_print()
{
    t_print *print;

    if (!(print = (t_print *)malloc(sizeof(t_print))))
        return (NULL);
    print->i = 0;
    print->str = NULL;
    print->int_return = 0;
    print->params = NULL;
    return (print);
}

void    print_width(t_flags *t_flags, bool boolean)
{
    int i;

    i = 0;
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

void    ft_printf(char *str, ...)
{
    va_list args;
    t_flags *flags;
    t_print *print;
    int nb_param;

    void  (*tabFunc[9])(va_list *, t_print *) = { get_char, get_str, get_int, get_int, get_int, get_int, get_xhexa, get_Xhexa };
    char params[9] = { 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%' };
    print = init_print();
    va_start(args, str);
    print->str = str;
    while (print->str[print->i] != '\0')
    {
        flags = init_flags();
        if (print->i != 0 && print->str[print->i - 1] == '%')
        {
            while (((nb_param = find_param(params, print)) < 0) && print->str[print->i])
            {
                find_flags(flags, print);
                print->i++;
            }
            if (nb_param < 9 && nb_param >= 0)
            {
                (*tabFunc[nb_param]) (&args, print);
                if (nb_param >= 3 && nb_param <= 7)
                {
                    flags->width -= (flags->precision > ft_strlen(print->params) ? flags->precision : ft_strlen(print->params));
                    flags->precision -= ft_strlen(print->params);
                }
                else
                {
                    //flags->width -= ft_strlen(print->params);
                    // printf("\npres:%d\n", flags->precision);
                    // printf("\nparam:%s\n", print->params);
                    if (flags->precision >= 0) 
                        ft_memset(print->params, '\0', flags->precision);// : NULL;
                    flags->width -= ft_strlen(print->params);
                    //flags->precision = 0;    // avec str si precision > strlen on s'en fout  
                }
                if (flags->moins)  // espace a droite - over ride le 0
                {
                    print_precision(flags);
                    ft_putstr(print->params);
                    print_width(flags, false);
                }
                else 
                {
                    print_width(flags, flags->zero);
                    print_precision(flags);
                    ft_putstr(print->params);
                }
            }   
            }
        else if (print->str[print->i] != '%')
        {
            write(1, &print->str[print->i], 1);
        }
        //free(print->params);
        print->i++;
    }
    //return (ft_strlen(results));
}

int main() 
{
    ft_printf("Raphael est ma %10.2s, %5s, x%10.0x\n", "bonjour", "au", 15);
    printf("Raphael est ma %10.2s, %5s, x%10.0x\n", "bonjour", "au", 15);
}