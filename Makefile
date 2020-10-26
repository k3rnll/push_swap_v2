# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 12:41:37 by k3                #+#    #+#              #
#    Updated: 2020/10/26 12:41:37 by k3               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBR = -L$(LIB_DIR) -lft
INCL = -I$(HDR_DIR) -I$(LIB_HDR)

LIB = $(LIB_DIR)libft.a
LIB_DIR = ./libft/
LIB_HDR = $(LIB_DIR)includes/

HDR_DIR = ./include/
HDR_LIST = push_swap.h
HDR = $(addprefix $(HDR_DIR), $(HDR_LIST))

SRC_DIR = ./src/
SRC_LIST = 	find.c put_ab.c rotate_ab.c \
		smart_rt.c switch_ab.c up_dw.c \
		helper.c helper2.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY: all clean fclean re

all: $(NAME) $(NAME2)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ) $(OBJ_DIR)push_swap.o
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(OBJ_DIR)push_swap.o $(LIBR)
	@echo $@ Done

$(NAME2): $(LIB) $(OBJ_DIR) $(OBJ) $(OBJ_DIR)checker.o
	@$(CC) $(FLAGS) -o $(NAME2) $(OBJ) $(OBJ_DIR)checker.o $(LIBR)
	@echo $@ Done

$(OBJ_DIR)checker.o: $(SRC_DIR)checker.c $(HDR)
	@$(CC) $(FLAGS) $(INCL) -o $@ -c $<
	@echo OBJECT: $@ updated

$(OBJ_DIR)push_swap.o: $(SRC_DIR)push_swap.c $(HDR)
	@$(CC) $(FLAGS) $(INCL) -o $@ -c $<
	@echo OBJECT: $@ updated

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo OBJECT_DIRECTORY is created

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	@$(CC) $(FLAGS) $(INCL) -o $@ -c $<
	@echo OBJECT: $@ updated

$(LIB):
	@$(MAKE) -C $(LIB_DIR)
	@echo libft Done

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo clean Done

fclean:
	@$(MAKE) clean
	@rm -f $(LIB)
	@rm -f $(NAME) $(NAME2)
	@echo fclean Done

re:
	@$(MAKE) fclean
	@$(MAKE) all
