SRCS = srcs/push_swap.c \
	srcs/sort_alg/swap.c

OBJS = $(SRCS:.c=.o) 

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

INCL = -I includes

.c.o:

all: $(NAME)

$(NAME): 
	$(CC) $(INCL) $(SRCS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
