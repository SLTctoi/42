# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: <your_login>                              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/02                          #+#    #+#                  #
#    Updated: 2026/03/02                         ###   ########.fr            #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = inception

# Paths
SRCS_DIR = srcs
COMPOSE_FILE = $(SRCS_DIR)/docker-compose.yml
ENV_FILE = $(SRCS_DIR)/.env

# Docker compose command
DOCKER_COMPOSE = docker compose -f $(COMPOSE_FILE)

# Volume paths (will be created on host)
VOL_PATH = /home/$(USER)/data
MARIADB_VOL = $(VOL_PATH)/mariadb
WORDPRESS_VOL = $(VOL_PATH)/wordpress

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: up

# Create necessary directories
$(VOL_PATH):
	@echo "$(YELLOW)Creating volume directories...$(NC)"
	@mkdir -p $(MARIADB_VOL)
	@mkdir -p $(WORDPRESS_VOL)
	@echo "$(GREEN)Volume directories created!$(NC)"

# Build images
build: $(VOL_PATH)
	@echo "$(YELLOW)Building Docker images...$(NC)"
	@$(DOCKER_COMPOSE) build
	@echo "$(GREEN)Build complete!$(NC)"

# Start containers
up: $(VOL_PATH)
	@echo "$(YELLOW)Building images...$(NC)"
	@$(DOCKER_COMPOSE) build
	@echo "$(YELLOW)Starting containers...$(NC)"
	@$(DOCKER_COMPOSE) up -d
	@echo "$(GREEN)Containers started!$(NC)"
	@echo "$(GREEN)Access your site at: https://$(USER).42.fr$(NC)"

# Stop containers
down:
	@echo "$(YELLOW)Stopping containers...$(NC)"
	@$(DOCKER_COMPOSE) down
	@echo "$(GREEN)Containers stopped!$(NC)"

# Start containers (already built)
start:
	@echo "$(YELLOW)Starting containers...$(NC)"
	@$(DOCKER_COMPOSE) start
	@echo "$(GREEN)Containers started!$(NC)"

# Stop containers (without removing)
stop:
	@echo "$(YELLOW)Stopping containers...$(NC)"
	@$(DOCKER_COMPOSE) stop
	@echo "$(GREEN)Containers stopped!$(NC)"

# Show logs
logs:
	@$(DOCKER_COMPOSE) logs -f

# Show status
status:
	@$(DOCKER_COMPOSE) ps

# Clean containers and network
clean:
	@echo "$(YELLOW)Cleaning containers and network...$(NC)"
	@$(DOCKER_COMPOSE) down --volumes
	@echo "$(GREEN)Cleanup complete!$(NC)"

# Full clean (containers, images, volumes, and host directories)
fclean: clean
	@echo "$(RED)Removing all Docker images, volumes and data...$(NC)"
	@docker system prune -af --volumes
	@sudo rm -rf $(VOL_PATH)
	@echo "$(GREEN)Full cleanup complete!$(NC)"

# Rebuild everything
re: fclean all

# Show help
help:
	@echo "$(GREEN)Available commands:$(NC)"
	@echo "  make          - Build and start all containers"
	@echo "  make build    - Build Docker images"
	@echo "  make up       - Start containers in detached mode"
	@echo "  make down     - Stop and remove containers"
	@echo "  make start    - Start existing containers"
	@echo "  make stop     - Stop containers without removing"
	@echo "  make logs     - Follow container logs"
	@echo "  make status   - Show container status"
	@echo "  make clean    - Remove containers and volumes"
	@echo "  make fclean   - Remove everything (images, volumes, data)"
	@echo "  make re       - Full rebuild"

.PHONY: all build up down start stop logs status clean fclean re help
