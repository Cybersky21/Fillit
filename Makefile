#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrooks <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/31 20:15:06 by acrooks           #+#    #+#              #
#    Updated: 2019/03/31 17:40:17 by acrooks          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =	srcs/base.c srcs/edit_tetra_map.c srcs/map.c srcs/read_tetra.c \
		srcs/validation.c srcs/main.c 

INCLUDES = -I ./includes
OBJECTS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = ./libft/libft.a
LIBLINK = -L ./libft -lft
LIBINK = -I ./libft

all: $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) $(LIBINK) $(INCLUDES) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK"

$(NAME): libft $(OBJECTS)
	@echo "Compiling fillit..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJECTS)
	@echo "OK"

rmlib:
	@echo "Deliting libft objects files..."
	@make fclean -C ./libft
	@echo "OK"

clean: rmlib
	@echo "Deliting fillit objects files..."
	@rm -rf $(OBJECTS)
	@echo "OK"

fclean: clean
	@echo "Deliting fillit..."
	@rm -rf $(NAME)
	@echo "OK"

re: fclean all
