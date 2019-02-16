# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/16 17:28:51 by tferrieu          #+#    #+#              #
#    Updated: 2019/02/16 17:45:08 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG-C		=	-c -Wall -Wextra -Werror \

FLG-O		=	-Wall -Wextra -Werror \
				-lmlx -framework OpenGL -framework AppKit -o

CC			=	cc

NAME		=	fdf

SRC-C		=	./calculate_flat.c \
				./calculate_tilt.c \
				./camera_movement.c \
				./clean_free.c \
				./draw_line.c \
				./init_mlx.c \
				./input_hook.c \
				./loop_hook.c \
				./mlxmain.c \
				./parsing.c \
				./program_close.c

SRC-O		=	$(SRC-C:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C libft/
	$(CC) $(FLG-C) $(SRC-C)
	$(CC) $(FLG-O) $(NAME) $(SRC-O) libft/libft.a

clean:
	$(MAKE) -C libft/ clean
	rm -f $(SRC-O)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
