# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 00:02:38 by jimpark           #+#    #+#              #
#    Updated: 2023/01/25 16:35:45 by jimpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putdem.c \
		ft_puthex.c \
		ft_putpt.c \
		ft_putstr.c \
		ft_putudem.c \
		utils.c

OBJECTS = $(SRCS:.c=.o)

$(NAME) : $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
