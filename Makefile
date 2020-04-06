# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rick <rick@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 22:55:30 by ojessi            #+#    #+#              #
#    Updated: 2020/04/06 11:14:23 by rick             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME_PUSHSWAP = push_swap
NAME_CHECKER = checker

ID = $(shell id -un)
CC =	gcc
FLAGS =	-g # -Wall -Wextra -Werror
LIBRARIES =	-L $(LIBFT_DIR) -lft
INCLUDES =	-I $(HEADERS_DIR) -I $(LIBFT_HEADERS)

# LIBFT
LIBFT_DIR =	./libft
#LIBFT =		$(LIBFT_DIR)libft.a
LIBFT = ./libft/libft.a
LIBFT_HEADERS =	$(LIBFT_DIR)/includes/

#HEADERS
HEADERS_LIST =	push_swap.h
HEADERS_DIR =	./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#SOURCES
SRC_DIR =	./src/

SRC_P =	push_swap.c
SRC_C =	checker.c

SRC_LIST =	command_actions.c \
			command_additionals.c \
			input_checker.c \
			list_actions_1.c \
			list_actions_2.c \
			list_additionals.c \
			list_indexing.c \
			operation_list_a.c \
			operation_list_b.c \
			operation_list_ab.c \
			print_additionals.c \
			solve_additionals_1.c \
			solve_additionals_2.c \
			solve_algoritm_1.c \
			solve_algoritm_2.c \
			push_swap_additionals.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_PUSH = $(addprefix $(SRC_DIR), $(SRC_P))
SRC_CHECKER = $(addprefix $(SRC_DIR), $(SRC_C))

#OBJECTS
OBJ_DIR = obj/
OBJ_L = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ_L_P = $(patsubst %.c, %.o, $(SRC_P))
OBJ_L_C = $(patsubst %.c, %.o, $(SRC_C))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_L))
OBJ_P = $(addprefix $(OBJ_DIR), $(OBJ_L_P))
OBJ_C = $(addprefix $(OBJ_DIR), $(OBJ_L_C))

# COLORS

GREEN =	\033[0;32m
RED =	\033[0;31m
RESET =	\033[0m

all: $(NAME_PUSHSWAP) $(NAME_CHECKER)

$(NAME_PUSHSWAP): $(LIBFT) $(OBJ_DIR) $(OBJ) $(OBJ_P)
	@$(CC) -o $(NAME_PUSHSWAP) $(FLAGS) $(INCLUDES) $(OBJ) $(OBJ_P) $(LIBRARIES)
	@echo "\n$(NAME_PUSHSWAP): $(GREEN)$(NAME_PUSHSWAP) object files were created$(RESET)"
	@echo "$(NAME_PUSHSWAP): $(GREEN)$(NAME_PUSHSWAP) was created$(RESET)"

$(NAME_CHECKER): $(LIBFT) $(OBJ_DIR) $(OBJ) $(OBJ_C)
	@$(CC)  -o $(NAME_CHECKER) $(FLAGS) $(INCLUDES) $(OBJ) $(OBJ_C) $(LIBRARIES)
	@echo "\n$(NAME_CHECKER): $(GREEN)$(NAME_CHECKER) object files were created$(RESET)"
	@echo "$(NAME_CHECKER): $(GREEN)$(NAME_CHECKER) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME_PUSHSWAP): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME_PUSHSWAP): $(GREEN)creating $(LIBFT)...$(RESET)"
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME_PUSHSWAP): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME_PUSHSWAP): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME_PUSHSWAP): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME_PUSHSWAP)
	@echo "$(NAME_PUSHSWAP): $(RED)$(NAME_PUSHSWAP) was deleted$(RESET)"
	@rm -f $(NAME_CHECKER)
	@echo "$(NAME_PUSHSWAP): $(RED)$(NAME_CHECKER) was deleted$(RESET)"

re:
	@make fclean
	@make all