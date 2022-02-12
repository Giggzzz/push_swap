# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 03:22:27 by gudias            #+#    #+#              #
#    Updated: 2022/02/11 20:10:17 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I includes
RM	= rm -f

LIBFT	= libft/libft.a

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS = 	operations/swap.c operations/push.c operations/rotate.c \
	operations/reverse_rotate.c \
	push_swap.c stack_utils.c check_args.c sort.c sort_3.c

OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o) 

$(OBJSDIR)/%.o: srcs/%.c
	mkdir -p $(OBJSDIR) $(OBJSDIR)/operations
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C libft

clean: 
	$(RM) -r $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
