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

FLAGS = -Wall -Wextra -Werror -I. -I ./libft/libft -I ./libft/printf

FRAME = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

LIB = -L libft/ -lft $(FRAME)

FDF_SRC_DIR = src/

HEADER = fdf.h

CFDF = main.c 1parse_file.c 2draw.c

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
	rm -fv $(FDF_OBJ)

re: fclean all
