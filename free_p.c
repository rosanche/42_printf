#include "printf.h"

t_p    *free_p(t_p *p)
{
    free(p->basex);
    //free(p->width);
    free(p->param);
    //free(p->precision);
    free(p->strwidth);
    return (p);
}