NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -crs
RM = rm -f
COMMAND_DIR = ./command/
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_FLAG = -L$(FT_PRINTF_DIR) -lftprintf
LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = ./libft
LIBFT_FLAG = -L$(LIBFT_DIR) -lft
LIBFT = $(LIBFT_DIF)/libft.a

SRCS = 	deque.c \
		init.c \
		push_swap.c \
		utils.c \
		$(COMMAND_DIR)push.c \
		$(COMMAND_DIR)reverse_rotate.c \
		$(COMMAND_DIR)rotate.c \
		$(COMMAND_DIR)swap.c \

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(LIBFTPRINTF)
			$(CC) $(CFLAGS) -g -fsanitize=address $(OBJECTS) $(LIBFT_FLAG) $(FT_PRINTF_FLAG) -o $(NAME)

$(LIBFTPRINTF) :
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

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
