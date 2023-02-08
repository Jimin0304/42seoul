NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_DIR = ./mandatory/lib/ft_printf
FT_PRINTF_FLAG = -L$(FT_PRINTF_DIR) -lftprintf

LIBFT_DIR = ./mandatory/lib/libft
LIBFT_FLAG = -L$(LIBFT_DIR) -lft

HEADER = -I ./include
SRC_DIR = ./mandatory/src/
COMMAND_DIR = ./mandatory/command/

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
		$(COMMAND_DIR)swap.c \


BONUS_HEADER = -I ./bonus/include
BONUS_COMMAND_DIR = ./bonus/command/
BONUS_SRC_DIR = ./bonus/src/

BONUS_SRCS = 	$(BONUS_SRC_DIR)push_swap_bonus.c \
				$(BONUS_SRC_DIR)libft_utils_bonus.c \
				$(BONUS_SRC_DIR)libft_utils2_bonus.c \
				$(BONUS_SRC_DIR)utils1_bonus.c \
				$(BONUS_SRC_DIR)utils2_bonus.c \
				$(BONUS_SRC_DIR)gnl_bonus.c \
				$(BONUS_SRC_DIR)deque_bonus.c \
				$(BONUS_SRC_DIR)ft_split_bonus.c \
				$(BONUS_COMMAND_DIR)push_bonus.c \
				$(BONUS_COMMAND_DIR)reverse_rotate_bonus.c \
				$(BONUS_COMMAND_DIR)rotate_bonus.c \
				$(BONUS_COMMAND_DIR)swap_bonus.c


OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus : $(NAME) $(NAME_BONUS)

$(NAME) : $(OBJECTS)
			@make -C $(FT_PRINTF_DIR)
			@make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJECTS) $(HEADER) $(LIBFT_FLAG) $(FT_PRINTF_FLAG) -o $(NAME)

$(NAME_BONUS) : $(BONUS_OBJECTS)
			$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(BONUS_HEADER) -o $(NAME_BONUS)

clean :
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
