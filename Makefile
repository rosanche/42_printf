# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguenel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 14:09:25 by aguenel           #+#    #+#              #
#    Updated: 2019/12/16 14:09:28 by aguenel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc -Wall -Wextra -Werror $(PRINTF_H)

PRINTF_H = -I includes/libftprintf.h

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

SRC= get_type.c\
init.c\
printf_utils.c\
printf_utils_1.c\
printf_utils_2.c\
printf.c\
printf_1.c\
printf_2.c\
get_type_1.c\
ft_checkerror.c\
print_str.c \
print_char.c \
print_nbr.c \


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










