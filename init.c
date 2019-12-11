#include "ft_printf.h"
#include "libft/libft.h"

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
