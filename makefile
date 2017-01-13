# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apissier <apissier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 17:55:27 by apissier          #+#    #+#              #
#    Updated: 2017/01/13 17:47:21 by apissier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRC = $(SRCDIR)ft_get_tetro.c \
	$(SRCDIR)ft_read_file.c \
	$(SRCDIR)ft_binary.c \
	$(SRCDIR)ft_solve.c \
	$(SRCDIR)ft_error.c \
	$(SRCDIR)ft_print_result.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a
LIBINC = -I./libft
LIBLINK = -L./libft -lft

SRCDIR = ./src/
INCDIR = ./includes/

all: $(NAME)

$(NAME):
		make -C ./libft/
		@$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME) $(SRCDIR)ft_fillit.c

clean:
			rm -rf $(OBJ)
			make -C ./libft clean

fclean: clean
			rm -f $(NAME)
			make -C ./libft fclean

re: fclean all
