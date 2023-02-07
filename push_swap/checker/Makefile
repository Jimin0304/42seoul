NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

COMMAND_DIR = ./command/
SRC_DIR = ./src/

HEADER = -I ./include

SRCS = 	$(SRC_DIR)push_swap_bonus.c \
		$(SRC_DIR)libft_utils_bonus.c \
		$(SRC_DIR)libft_utils2_bonus.c \
		$(SRC_DIR)utils1_bonus.c \
		$(SRC_DIR)utils2_bonus.c \
		$(SRC_DIR)gnl_bonus.c \
		$(SRC_DIR)deque_bonus.c \
		$(SRC_DIR)ft_split_bonus.c \
		$(COMMAND_DIR)push_bonus.c \
		$(COMMAND_DIR)reverse_rotate_bonus.c \
		$(COMMAND_DIR)rotate_bonus.c \
		$(COMMAND_DIR)swap_bonus.c

OBJECTS = $(SRCS:.c=.o)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) $(HEAEER) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
