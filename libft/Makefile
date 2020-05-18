# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 15:28:54 by ojessi            #+#    #+#              #
#    Updated: 2019/06/11 12:34:11 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

ID = $(shell id -un)
CC =	gcc
FLAGS =	-g -Wall -Wextra -Werror
INCLUDES =	-I $(HEADERS_DIR)

#HEADERS
HEADERS_LIST =	libft.h \
				get_next_line.h \

HEADERS_DIR =	./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#SRC
SRC_DIR =	./src/

SRC_LIST	=	ft_abs.c \
				ft_absf.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_count_words.c \
				ft_ftoa.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_itoa.c \
				ft_lstadd.c \
				ft_lstaddback.c \
				ft_lstcheck_contentsize.c \
				ft_lstdel_contentsize.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_ltoa_base.c \
				ft_ltoa.c \
				ft_max.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_min.c \
				ft_pow.c \
				ft_putchar_fd.c \
				ft_putchar.c \
				ft_putendl_fd.c \
				ft_putendl.c \
				ft_putnbr_fd.c \
				ft_putnbr.c \
				ft_putstr_fd.c \
				ft_putstr.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtolower.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

#OBJECTS
OBJ_DIR = obj/
OBJ_L = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_L))

# COLORS

GREEN =	\033[0;32m
RED =	\033[0;31m
RESET =	\033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@make fclean
	@make all