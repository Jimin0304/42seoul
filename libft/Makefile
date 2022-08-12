# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 20:03:03 by jimpark           #+#    #+#              #
#    Updated: 2022/08/10 15:02:01 by jimpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ./ft_isalpha.c \
	   ./ft_isdigit.c \
	   ./ft_isalnum.c \
	   ./ft_isascii.c \
	   ./ft_isprint.c \
	   ./ft_strlen.c \
	   ./ft_memset.c \
	   ./ft_bzero.c \
	   ./ft_memcpy.c \
	   ./ft_memmove.c \
	   ./ft_strlcpy.c \
	   ./ft_strlcat.c \
	   ./ft_toupper.c \
	   ./ft_tolower.c \
	   ./ft_strchr.c \
	   ./ft_strrchr.c \
	   ./ft_strncmp.c \
	   ./ft_memchr.c \
	   ./ft_memcmp.c \
	   ./ft_strnstr.c \
	   ./ft_atoi.c \
	   ./ft_calloc.c \
	   ./ft_strdup.c \
	   ./ft_substr.c \
	   ./ft_strjoin.c \
	   ./ft_strtrim.c \
	   ./ft_split.c \
	   ./ft_itoa.c \
	   ./ft_strmapi.c \
	   ./ft_striteri.c \
	   ./ft_putchar_fd.c \
	   ./ft_putstr_fd.c \
	   ./ft_putendl_fd.c \
	   ./ft_putnbr_fd.c \

SRCS_B = ./ft_lstnew.c \
		 ./ft_lstadd_front.c \
		 ./ft_lstsize.c \
		 ./ft_lstlast.c \
		 ./ft_lstadd_back.c \
		 ./ft_lstdelone.c \
		 ./ft_lstclear.c \
		 ./ft_lstiter.c \
		 ./ft_lstmap.c \

OBJECTS = $(SRCS:.c=.o)

OBJECTS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJECTS) $(OBJECTS_B)
else
	OBJ_FILES = $(OBJECTS)
endif

$(NAME) : $(OBJ_FILES)
		$(AR) $(NAME) $(OBJ_FILES)

all : $(NAME)
	sleep 1

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

bonus :
	make WITH_BONUS=1 all

clean :
	$(RM) $(OBJECTS) $(OBJECTS_B)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re
