# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mderome <mderome@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 09:41:40 by mderome           #+#    #+#              #
#    Updated: 2021/10/12 12:09:15 by mderome          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC = 	ft_atoi.c				\
		ft_bzero.c 				\
		ft_calloc.c				\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isprint.c			\
		ft_itoa.c				\
		ft_memccpy.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_memset.c				\
		ft_putchar_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_putstr_fd.c			\
		ft_split.c				\
		ft_strchr.c				\
		ft_strdup.c				\
		ft_strjoin.c			\
		ft_strlcat.c			\
		ft_strlcpy.c			\
		ft_strlen.c				\
		ft_strlcpy.c			\
		ft_strncmp.c			\
		ft_strnstr.c			\
		ft_strrchr.c			\
		ft_strtrim.c			\
		ft_substr.c				\
		ft_tolower.c			\
		ft_toupper.c			\
		ft_strmapi.c			\
		get_next_line.c			\
		get_next_line_utils.c	\

BONUS = ft_lstsize.c		\
		ft_lstnew.c			\
		ft_lstlast.c		\
		ft_lstclear.c		\
		ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c		\

HEADER = includes
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

BNS = $(BONUS:.c=.o)

.o.c :
		$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

all :		$(NAME)

$(NAME):	$(OBJ)
			ar -rc $(NAME) $(OBJ)
		       	rm -rf $(OBJ)	
bonus :	$(BNS)
			ar -rc $(NAME) $(BNS)
				rm -rf $(BNS)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY:	libft.a all clean fclean re
