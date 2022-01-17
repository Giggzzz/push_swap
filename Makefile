# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 03:22:27 by gudias            #+#    #+#              #
#    Updated: 2022/01/17 04:52:46 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/push_swap.c \
	srcs/sort_alg/swap.c

OBJS = $(SRCS:.c=.o) 

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

INCL = -I includes

LIBFT = libft/libft.a

.c.o:

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(INCL) $(SRCS) $(LIBFT) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
