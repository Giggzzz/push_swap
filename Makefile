# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 03:22:27 by gudias            #+#    #+#              #
#    Updated: 2022/03/10 12:46:15 by gudias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I includes
RM		= rm -f

LIBFT	= libft/libft.a

SRCSDIR	= srcs
OBJSDIR	= objs

SRCS 	= 	operations/swap.c operations/push.c operations/rotate.c \
			operations/reverse_rotate.c push_swap.c stack_utils.c \
			check_args.c sort_3.c memfree.c sort_handler.c calc_pivot.c \
			chunk_utils.c compare_2.c is_sorted.c \
			quicksort_a.c quicksort_a_rev.c quicksort_b.c quicksort_b_rev.c \

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o) 

$(OBJSDIR)/%.o:	srcs/%.c
	mkdir -p $(OBJSDIR) $(OBJSDIR)/operations
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C libft

clean: 
	$(RM) -r $(OBJSDIR)
	make clean -C libft
	make clean -C checker_bonus

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C checker_bonus

re: fclean all

bonus:
	make -C checker_bonus

.PHONY: all clean fclean re bonus
