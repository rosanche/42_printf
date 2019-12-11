

#include "ft_printf.h"
#include "libft/libft.h"

// char    *transformnbr(int n)
// {
//     char *str;
//     int i;
// 	unsigned int nb;

// 	nb = n;
//     i = 0;
    
// 	if (n < 0)
// 	{
// 		nb = -n;
//         i++;
// 	}
//     while (nb > 0)
//     {
//         i++;
//         nb /= 10;
//     }
//     if (!(str = (char *)malloc(sizeof(char) * i + 1)))
//         return (NULL);
//     nb = n;
//     i--;
//     while (nb > 0)
//     {
//         str[i] = nb % 10 + '0';
//         i--;
//         nb /= 10;
//     }
//     if (n < 0)
//         str[i] = '-';
// 	return (str);
// }

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

void    ft_printf(char *str, ...)
{
    va_list args;
    //t_print->flags *flags;
    t_print *print;
    int nb_param;

    void  (*tabFunc[9])(va_list *, t_print *) = { get_char, get_str, get_int, get_int, get_int, get_int, get_xhexa, get_Xhexa };
    char params[9] = { 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%' };
    print = init_print();
    va_start(args, str);
    print->str = str;
    while (print->str[print->i] != '\0')
    {
        print->flags = init_flags();
        if (print->i != 0 && print->str[print->i - 1] == '%')
        {
            while (((nb_param = find_param(params, print)) < 0) && print->str[print->i])
            {
                find_flags(print->flags, print);
                print->i++;
            }
            if (nb_param < 9 && nb_param >= 0)
            {
                (*tabFunc[nb_param]) (&args, print);
                printf("\nparam000: %s\n", print->params);
                /*if (nb_param >= 3 && nb_param <= 7)
                {
                    print->flags->width -= (print->flags->precision > ft_strlen(print->params) ? print->flags->precision : ft_strlen(print->params));
                    print->flags->precision -= ft_strlen(print->params);
                }*/
                // else
                // {

                    // if (print->flags->precision < ft_strlen(print->params)) 
                    // {
                    //     printf("\nparam:%se\n", print->params);
                    //     print->params[print->flags->precision] = '\0';
                    //     printf("\nparam:%se\n", print->params);
                    // }// : NULL;
                printf("\nparam001: %s\n", print->params);
                print->flags->width -= ft_strlen(print->params);
                printf("\nparam002: %s\n", print->params);
                print->flags->precision = 0;    // avec str si precision > strlen on s'en fout  
                printf("\nparam003: %s\n", print->params);
                if (print->flags->moins)  // espace a droite - over ride le 0
                {
                    //print_precision(print->flags);
                    ft_putstr(print->params);
                    print_width(print->flags, false, print);
                }
                else 
                {
                    printf("\nparam003: %s\n", print->params);
                    print_width(print->flags, print->flags->zero, print);
                    printf("\nparam004: %s\n", print->params);
                    ft_putstr(print->params);
                    //printf("\nstr:%s\n", print->params);
                }
            }   
            }
        else if (print->str[print->i] != '%')
            write(1, &print->str[print->i], 1);
        //free(print->params);
        print->i++;
    }
    //return (ft_strlen(results));
}

int main() 
{
    ft_printf("Raphael est ma %10.2s, %5s, x%10.1xe\n", "bonjour", "au", 15);
       printf("Raphael est ma %10.2s, %5s, x%10.1xe\n", "bonjour", "au", 15);
}