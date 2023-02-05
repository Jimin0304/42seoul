NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_FLAG = -L$(FT_PRINTF_DIR) -lftprintf

LIBFT_DIR = ./lib/libft
LIBFT_FLAG = -L$(LIBFT_DIR) -lft

HEADER = -I ./include
SRC_DIR = ./src/
COMMAND_DIR = ./command/

SRCS = 	$(SRC_DIR)deque.c \
		$(SRC_DIR)init.c \
		$(SRC_DIR)push_swap.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)sort_three.c \
		$(SRC_DIR)quicksort.c \
		$(SRC_DIR)sort.c \
		$(COMMAND_DIR)push.c \
		$(COMMAND_DIR)reverse_rotate.c \
		$(COMMAND_DIR)rotate.c \
		$(COMMAND_DIR)swap.c

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
			@make -C $(FT_PRINTF_DIR)
			@make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) -g -fsanitize=address $(OBJECTS) $(HEADER) $(LIBFT_FLAG) $(FT_PRINTF_FLAG) -o $(NAME)

clean :
	$(RM) $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
