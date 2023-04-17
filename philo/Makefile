# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 19:34:57 by jimpark           #+#    #+#              #
#    Updated: 2023/04/17 20:32:04 by jimpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
RM = rm -f

HEADER = -I ./includes
SRC_DIR = ./srcs/

SRCS = 	$(SRC_DIR)action.c \
		$(SRC_DIR)init.c \
		$(SRC_DIR)main.c \
		$(SRC_DIR)utils.c \

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) $(HEADER) -o $(NAME)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
