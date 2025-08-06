# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 19:46:51 by alhamdan          #+#    #+#              #
#    Updated: 2024/11/27 20:25:48 by alhamdan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = cub

cub_SRC = cub3D.c

cub_OBJ = $(cub_SRC:.c=.o)


LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)


$(NAME): $(cub_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(cub_OBJ) $(LIBFT) -o $(NAME)
	

clean:
	rm -f $(cub_OBJ)
	make clean -C $(LIBFT_DIR)


fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)


re: fclean all


$(LIBFT):
	make -C $(LIBFT_DIR)

.PHONY: all clean fclean re
