/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:46:01 by aguenel           #+#    #+#             */
/*   Updated: 2019/12/16 16:52:04 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdbool.h>

typedef	struct	s_p
{
	int			i;
	char		*src;
	char		*param;
	int			res;

	bool		moins;
	bool		zero;
	int			precision;
	int			width;
	bool		etoile;
	bool		pointetoile;
	int			nb_param;
	char		*strprecision;
	char		*strwidth;
	bool		nbrn;
	char		*basex;
	char		*basexx;
	int			count;
	bool		b_0;
	char		*params;
}				t_p;

t_p				*init_p(const char *src);
void			*init_f(t_p *p);

int				ft_printf(const char *str, ...);
char			*ft_p_util(char *str, int i);

size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(long long n);
unsigned int	ft_size(long long n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strjoin_char(char const *s1, char s2);
char			*ft_strnew(int size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
// void			fill_param(t_p *p, va_list *args);
int				ft_isdigit(int c);
void			ft_memset(t_p *p);
char			*ft_memmove(char *src);
void			ft_memsetzero(t_p *p);
void			ft_str(va_list *args, t_p *p);
void			ft_memsetpre(t_p *p);

void			ft_str(va_list *args, t_p *p);
void			ft_char(va_list *args, t_p *p);
void			ft_nbr(va_list *args, t_p *p);
void			ft_ui(va_list *args, t_p *p);
void			ft_x(va_list *args, t_p *p);
void			ft_xx(va_list *args, t_p *p);
void			ft_pc(t_p *p);
void			ft_p(va_list *args, t_p *p);
void			ft_diuxx(t_p *p);
int				find_flags_and_nbparam(t_p *p, va_list *args);
void			fill_param(t_p *p, va_list *args);
void			find_flags(t_p *p, va_list *args);
int				guess_width(t_p *p);
void   			print_smth(char c, int nb, t_p *p);
void			ft_01(t_p *p);
void			ft_02(t_p *p, int nb_param);
void			ft_03(t_p *p, int nb_param);
int				ft_checkerror(t_p *p);
void			ft_strdel(char **as);
void			guess_precision(t_p *p);
void			ft_putnbr(int n, int fd, t_p *p);

#endif
