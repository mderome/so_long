# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mderome <mderome@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 09:34:18 by mderome           #+#    #+#              #
#    Updated: 2021/11/29 09:45:34 by mderome          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
MLX_DIR			=	./mlx_linux/
SRC_DIR			=	./srcs/
INC_DIR			=	./includes/
SRCS			=	main.c			\
					check_map.c		\
					parsing_map.c	\
					error.c			\
					put_img.c		\
					free_all.c		\
					moove.c			\
					utils.c			\
					
					
SRC_BASENAME	=	$(addprefix $(SRC_DIR), $(SRCS))		
OBJS			=	$(SRC_BASENAME:.c=.o)
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -I $(MLX_DIR) -I $(INC_DIR) -I ./libft/

.c.o		:
				$(CC) $(FLAGS) -Imlx -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(MLX_DIR)
			make -C ./libft/
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -L./libft/ -lft -lmlx -lz -lbsd -lXext -lX11
			@echo [$(NAME)] : Created !

clean		:
			rm -rf $(OBJS)
			make fclean -C ./libft/
			make clean -C $(MLX_DIR)
			@echo "[OBJS] Deleted"

fclean		:	clean
			rm -f $(NAME)
			@echo "[$(NAME)]: Deleted"

re			:	fclean all
