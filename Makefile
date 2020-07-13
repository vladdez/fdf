# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 13:19:02 by kysgramo          #+#    #+#              #
#    Updated: 2020/02/25 13:19:09 by kysgramo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = fdf

FLAGS = -Wall -Wextra -Werror -I. -I ./libft/libft

FRAME = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

LIB = -L libft/ -lft $(FRAME)

FDF_SRC_DIR = src/

HEADER = fdf.h

CFDF = main/main.c read/parse_file.c read/parse_file1.c draw/draw_algo.c draw/draw_features.c \
read/structs.c control/key_managment_pt1.c control/key_managment_pt2.c control/key_managment_pt3.c control/rotation_managment.c \
	read/value_managment.c control/movement.c control/mouse.c

FDF_SRC = $(addprefix $(FDF_SRC_DIR),$(CFDF))

FDF_OBJ = $(FDF_SRC:%.c=%.o)


.PHONY: all clean fclean re

all: $(FDF)

$(FDF): $(FDF_OBJ) $(HEADER)
	make -C libft
	make -C minilibx_macos
	gcc $(FLAGS) $(FDF_OBJ) -o $(FDF) $(LIB)

$(FDF_SRC_DIR)%.o : $(FDF_SRC_DIR)%.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@


clean:
	@rm -f $(FDF_OBJ)

fclean: clean
	make fclean -C libft/
	rm -fv $(FDF_OBJ) $(FDF)

re: fclean all
