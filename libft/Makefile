# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamicel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/13 13:37:24 by pamicel           #+#    #+#              #
#    Updated: 2016/11/16 11:01:03 by pamicel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

CFILES = 			ft_bzero.c \
					ft_memalloc.c \
					ft_memcpy.c \
		 			ft_putchar.c \
		 			ft_putstr.c \
					ft_strnew.c \
					ft_strncmp.c \
					ft_strlen.c

OFILES = $(CFILES:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(NAME).a

$(NAME).a : $(OFILES)
	@ar rc $(NAME).a $(OFILES);
	@ranlib $(NAME).a

%.o : %.c
	@$(CC) -c -o $@ $(FLAGS) $<;

clean :
	@rm -f $(OFILES)

fclean :
	@rm -f $(OFILES) $(NAME).a

re: fclean all
