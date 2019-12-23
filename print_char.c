#include "printf.h"

void	ft_char(va_list *args, t_p *p)
{
	char	c;

	c = va_arg(*args, int);

    p->width -= p->precision < 1 && p->precision != -1 ? p->precision : 1;
    if (p->moins)
    {
        if ((c == '\0' || c == 0))
            ft_putchar_fd(0, 1);
        else
            write(1, &c, 1);
        ft_diuxx(p);
    }
    else
    {
        ft_diuxx(p);
        if ((c == '\0' || c == 0))
            ft_putchar_fd(0, 1);
        else
            write(1, &c, 1);
    }
    p->res++;
}