#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdarg.h>
#include    "./libft/libft.h"
#include    <stdbool.h>


typedef struct  s_flags 
{
    bool    moins;
    bool    zero;
    int     precision;
    int     width;
    bool    etoile;
}               t_flags;

typedef struct  s_print
{
    int     i;
    int     start;
    int     end;
    char    *str;
    char    *params;
    int     int_return;
    t_flags *flags;
}               t_print;

void    ft_printf(char *str, ...);
int     find_param(char *params, t_print *print);
void    get_str(va_list *list, t_print *print);
void    get_int(va_list *list, t_print *print);
void    get_char(va_list *list, t_print *print);
void    get_Xhexa(va_list *list, t_print *print);
void    get_xhexa(va_list *list, t_print *print);
char			*ft_itoan(long long n);
t_flags     *init_flags();
t_print *init_print();
void    print_precision(t_flags *precision);
int     guess_width(t_print *print);
void    find_flags(t_flags *flags, t_print *print);
void    print_width(t_flags *t_flags, bool boolean, t_print *print);

#endif