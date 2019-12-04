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
    int i;
    int start;
    int end;
    char *str;
    char *params;
    int int_return;
}               t_print;

void    ft_printf(char *str, ...);
int     find_param(char *params, t_print *print);
void    get_str(va_list *list, t_print *print);
void    get_int(va_list *list, t_print *print);
void    get_char(va_list *list, t_print *print);
void    get_Xhexa(va_list *list, t_print *print);
void    get_xhexa(va_list *list, t_print *print);

#endif