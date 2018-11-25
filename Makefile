# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echouvet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 19:06:28 by echouvet          #+#    #+#              #
#    Updated: 2018/03/07 06:29:40 by echouvet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
INCLUDES = wolf.h

LIB = ./libft
LIBPATH = libft/libft.a

SRC = main.c \
parser.c \
basics.c \
raycasting.c \
move.c \
textures.c \
background_minimap.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra
EXT = -framework OpenGL -framework Appkit

all: $(NAME)
	
$(NAME): $(OBJ)
	@make -C $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH) $(EXT) mlx/libmlx.a

clean:
	rm -rf $(OBJ)
	make clean -C $(LIB)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB)

norme:
	norminette $(SRC) $(INCLUDES)

normeerrors:
	norminette $(SRC) $(INCLUDES) libft/* | grep -b1 Error

debug:
	$(CC) $(CFLAGS) -g3 -fsanitize=address -o $(NAME) $(OBJ) $(LIBPATH) $(EXT)

re: fclean all

.PHONY: all, re, clean, fclean, norme, normeerrors, debug, re
