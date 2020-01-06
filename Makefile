# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 20:45:34 by rosanche          #+#    #+#              #
#    Updated: 2020/01/02 20:46:07 by rosanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc -Wall -Wextra -Werror $(PRINTF_H)

PRINTF_H = -I includes/libftprintf.h

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

SRC= init.c\
printf_utils.c\
printf_utils_1.c\
printf.c\
printf_1.c\
ft_checkerror.c \
print_str.c \
print_char.c \
print_nbr.c \
print_x.c \
print_xx.c \
print_u.c \
print_p.c \
print_percent.c \


OBJ=$(SRC:.c=.o)

$(NAME): 
	$(CC) -c $(SRC)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: clean, fclean










