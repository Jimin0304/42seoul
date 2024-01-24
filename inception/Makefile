VOLUME_PATH		:= /home/jimpark/data

all: setup

setup:
	@sudo mkdir -p $(VOLUME_PATH)/mariadb/
	@sudo mkdir -p $(VOLUME_PATH)/wordpress/
	@echo "Data directory created."
	@docker compose -f ./srcs/docker-compose.yml up --build -d
	@echo "Containers started."

up:
	@docker compose -f ./srcs/docker-compose.yml up -d
	@echo "Containers started."

down:
	@docker compose -f ./srcs/docker-compose.yml down
	@echo "Containers stopped."

clean:
	@docker compose -f ./srcs/docker-compose.yml down --rmi all --volumes
	@echo "Containers stopped and images removed."

fclean: clean
	@sudo rm -rf  $(VOLUME_PATH)
	@echo "Data directory removed."

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all setup up down clean fclean re