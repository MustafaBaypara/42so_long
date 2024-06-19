# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:47:29 by mbaypara          #+#    #+#              #
#    Updated: 2024/05/22 11:57:02 by mbaypara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                = so_long
LIBFT               = ./libft/libft.a
MINILIBX            = ./mlx/libmlx.a
SRC_DIR             = src/
OBJ_DIR             = obj/
CC                  = cc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -f
SO_LONG_DIR         = $(SRC_DIR)main.c $(SRC_DIR)drawimg.c $(SRC_DIR)utils2.c \
						$(SRC_DIR)utils.c $(SRC_DIR)snake.c $(SRC_DIR)initimages.c \
						$(SRC_DIR)snakemoves.c $(SRC_DIR)parserutils.c $(SRC_DIR)parser.c \
						$(SRC_DIR)valid.c
SRCS                = $(SO_LONG_DIR)
OBJ                 = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
all:                $(NAME)
$(NAME):            $(OBJ) $(LIBFT) $(MINILIBX)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
$(LIBFT):
					@make -C ./libft
$(MINILIBX):
					@make -C ./mlx
$(OBJ_DIR)%.o:      $(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) -Imlx $(INC) -c $< -o $@
clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
					@make clean -C ./mlx
fclean:             clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
re:                 fclean all
.PHONY:             all clean fclean re
