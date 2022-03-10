# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 03:22:27 by gudias            #+#    #+#              #
#    Updated: 2022/03/10 12:42:19 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../checker

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I ./srcs/
RM		= rm -f

LIBFT	= ../libft/libft.a

OBJSDIR	= objs

SRCS	= 	operations/swap.c operations/push.c operations/rotate.c \
			operations/reverse_rotate.c \
			stack_utils.c check_args.c checker.c

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o) 

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
