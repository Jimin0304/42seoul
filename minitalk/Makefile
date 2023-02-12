NAME =
CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_FLAG = -L$(FT_PRINTF_DIR) -lftprintf

HEADER = -I ./include
SRCS_DIR = ./src/

SRC = $(SRCS_DIR)utils.c
SRC_CLIENT = $(SRCS_DIR)client.c
SRC_SERVER = $(SRCS_DIR)server.c

SRC_OBJ = $(SRC:.c=.o)
CLIENT_OBJ = $(SRC_CLIENT:.c=.o)
SERVER_OBJ = $(SRC_SERVER:.c=.o)

all : $(CLIENT) $(SERVER)

$(NAME) : all

$(CLIENT) : $(CLIENT_OBJ) $(SRC_OBJ)
			@make -C $(FT_PRINTF_DIR)
			$(CC) $(CFLAGS) $(CLIENT_OBJ) $(SRC_OBJ) $(HEADER) $(FT_PRINTF_FLAG) -o $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(SRC_OBJ)
			@make -C $(FT_PRINTF_DIR)
			$(CC) $(CFLAGS) $(SERVER_OBJ) $(SRC_OBJ) $(HEADER) $(FT_PRINTF_FLAG) -o $(SERVER)

clean :
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(SRC_OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean : clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
