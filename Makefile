# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:37:19 by kbutor-b          #+#    #+#              #
#    Updated: 2023/11/23 12:44:04 by kbutor-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERS = ft_printf.h

CFILES = ft_convert_base.c \
			ft_convert_base2.c \
			ft_itoa.c \
			ft_printf.c \
			put.c \
			print_str.c \
			print_x.c \

OFILES = $(CFILES:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY :
	all clean fclean re