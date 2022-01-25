/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:45 by gudias            #+#    #+#             */
/*   Updated: 2022/01/25 04:20:10 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_elem {
	int		value;
	struct s_elem	*prev;
	struct s_elem	*next;
}		t_elem;

typedef struct s_stack {
	char	id;
	t_elem	*top;
	t_elem	*bot;
}		t_stack;

int	check_args(char **argv);
t_stack	*init_stack(char **values, char id);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

void	sort(t_stack *stack_a, t_stack *stack_b);

void	swap(t_stack *stack);
void	push(t_stack *dst_stack, t_stack *src_stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif
