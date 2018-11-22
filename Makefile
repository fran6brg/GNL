#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:33:34 by fberger           #+#    #+#              #
#    Updated: 2018/11/22 03:03:38 by fberger          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=*.c\
	Libft/*.c\

OBJS=*.o

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
