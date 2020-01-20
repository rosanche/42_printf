/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:44:56 by rosanche          #+#    #+#             */
/*   Updated: 2020/01/03 15:34:33 by rosanche         ###   ########.fr       */
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
	int			res;

	bool		moins;
	bool		zero;
	int			precision;
	int			width;
	bool		etoile;
	bool		pointetoile;
	int			nb_param;
	bool		nbrn;
	char		*basex;
	char		*basexx;
	int			count;
	bool		b_0;
	char		*params;
	bool		bprecision;
	bool		lettre;
	bool		done;
	bool		pair;
}				t_p;

t_p				*init_p(const char *src);
void			*init_f(t_p *p);

int				ft_printf(const char *str, ...);

size_t			ft_strlen(const char *str);
unsigned int	ft_size(long long n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strnewm(int size);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
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
void			print_smth(char c, int nb, t_p *p);
int				ft_checkerror(t_p *p);
void			ft_putnbr_x(unsigned int n, int fd, t_p *p);
unsigned int	ft_size_x(unsigned int n);
void			width_n_precision(t_p *p, int d);
void			convert_u(unsigned int nb, t_p *p);
void			ft_percent(t_p *p);
void			ft_putnstr_fd(char *s, int fd, int size);
void			ft_putnbr_fd(int n, int fd, t_p *p);
void			ft_putnbr_u(unsigned int n, int fd, t_p *p);

#endif
