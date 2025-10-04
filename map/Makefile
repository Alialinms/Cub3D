# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 19:46:51 by alhamdan          #+#    #+#              #
#    Updated: 2025/10/04 02:19:26 by alhamdan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = cub

SRC = char_and_second_skip check_form check_form_2 color_and_first_skip init_and_error main_map player_cols read_save_search uitil

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:=.o))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)


fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)


re: fclean all


$(LIBFT):
	make -C $(LIBFT_DIR)

.PHONY: all clean fclean re
