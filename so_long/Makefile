NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I ./include
MLX_DIR = ./mlx
MFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
AR = ar -crs
RM = rm -f
SRC_DIR = ./src/
BONUS_DIR = ./src_bonus/
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_FLAG = -L$(FT_PRINTF_DIR) -lftprintf
LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBMLX = $(MLX_DIR)/libmlx.a


SRCS = 	$(SRC_DIR)so_long.c \
		$(SRC_DIR)get_next_line.c \
		$(SRC_DIR)get_next_line_utils.c \
		$(SRC_DIR)init.c \
		$(SRC_DIR)check.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)move.c \
		$(SRC_DIR)dfs.c \
		$(SRC_DIR)player_move.c

SRCS_B = 	$(BONUS_DIR)so_long_bonus.c \
			$(BONUS_DIR)get_next_line_bonus.c \
			$(BONUS_DIR)get_next_line_utils_bonus.c \
			$(BONUS_DIR)init_bonus.c \
			$(BONUS_DIR)check_bonus.c \
			$(BONUS_DIR)utils_bonus.c \
			$(BONUS_DIR)move_bonus.c \
			$(BONUS_DIR)dfs_bonus.c \
			$(BONUS_DIR)player_move_bonus.c \
			$(BONUS_DIR)coin_move_bonus.c \
			$(BONUS_DIR)make_enemy_bonus.c \
			$(BONUS_DIR)score_bonus.c

OBJECTS = $(SRCS:.c=.o)
OBJECTS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFTPRINTF) $(LIBMLX)
			$(CC) $(CFLAGS) $(OBJECTS) $(HEADERS) $(MFLAGS) $(FT_PRINTF_FLAG) -o $(NAME)

$(NAME_BONUS) : $(OBJECTS_B) $(LIBFTPRINTF) $(LIBMLX)
			$(CC) $(CFLAGS) $(OBJECTS_B) $(HEADERS) $(MFLAGS) $(FT_PRINTF_FLAG) -o $(NAME_BONUS)

$(LIBFTPRINTF) :
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBMLX) :
	$(MAKE) -C $(MLX_DIR)

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJECTS) $(OBJECTS_B)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
