# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 14:08:57 by mkabirov          #+#    #+#              #
#    Updated: 2019/11/16 17:54:03 by mkabirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
SOURCES=./*.c
LIBRARIES=libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/
	gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LIBRARIES) $(FRAEMWORKS)

run42:
	./fdf test_maps/42.fdf

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
