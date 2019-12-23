#include "printf.h"

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

void	ft_putnbr_fd(int n, int fd, t_p *p)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
		nb = -n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd, p);
	ft_putchar_fd(nb % 10 + '0', fd);
    p->res++;
}

void	ft_di(t_p *p, int num)
{
	if (p->width >= 1)
	{
		if ((!p->moins) && (p->zero) && p->precision == -1
			&& p->width > p->precision)
		{
             if (p->nbrn)
                ft_putchar_fd('-', 1);
            print_smth('0', p->width, p);
            ft_putnbr_fd(num, 1, p);
		}
		else if (p->moins)
        {
              if (p->nbrn)
                 ft_putchar_fd('-', 1);
            ft_putnbr_fd(num, 1, p);
            print_smth(' ', p->width, p);
        }
        else
        {  
            if (p->precision > 0 && p->nbrn)
                p->width--; 
            print_smth(' ', p->width, p);
            if (p->precision != 0)
            {
                if (p->nbrn)
                {    
                    ft_putchar_fd('-', 1);
                    p->precision++;
                }
                print_smth('0', p->precision, p);  
                ft_putnbr_fd(num, 1, p);
            }
        }

	}
    else
    {    if (p->nbrn)
            ft_putchar_fd('-', 1);
        p->precision = p->nbrn ? p->precision + 1 : p->precision;
        print_smth('0', p->precision, p);
        ft_putnbr_fd(num, 1, p);
    } 
}


void	ft_nbr(va_list *args, t_p *p)
{
	int		num;

	num = va_arg(*args, int);
    if (num < 0)
    {   
         p->nbrn = true;
         p->res++;
    }
    p->width -= (p->precision > (int)ft_size((long long)num))
    && p->precision != -1 ? p->precision : (int)ft_size((long long)num);
    if (p->precision != 0)
        p->precision = p->precision > (int)ft_size((long long)num)  ? 
        p->precision - (int)ft_size((long long)num) : -1;
    if (p->moins && p->precision == -1)
    {
        print_smth('0', p->precision, p);
        ft_di(p, num);
    }
    else if(!(p->moins))
        ft_di(p, num);
    else if (p->precision == 0 && p->width > 0)
        print_smth(' ', p->width, p);
}