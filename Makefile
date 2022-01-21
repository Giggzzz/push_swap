# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 03:22:27 by gudias            #+#    #+#              #
#    Updated: 2022/01/21 08:16:44 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/push_swap.c srcs/stack_utils.c srcs/check_args.c\
	srcs/operations.c

OBJS = $(SRCS:.c=.o) 

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

INCL = -I includes

LIBFT = libft/libft.a

.c.o:

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(INCL) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
