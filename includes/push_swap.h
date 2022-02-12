/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:45 by gudias            #+#    #+#             */
/*   Updated: 2022/02/11 23:00:20 by gudias           ###   ########.fr       */
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
t_bool	is_sorted(t_elem *chunk_start, t_elem *chunk_end);
int	chunk_size(t_stack *stack, t_elem *chunk_end);

//RM
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	dummy_sort(t_stack *stack_a, t_stack *stack_b);

void	sort_3(t_stack *stack);
void	compare_2(t_stack *stack);

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);
void	quicksort_a_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);
void	quicksort_b(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);
void	quicksort_b_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);

void	swap_stack(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *dst_stack, t_stack *src_stack);
void	rotate_stack(t_stack *stack);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_stack(t_stack *stack);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif
