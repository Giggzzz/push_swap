/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:45 by gudias            #+#    #+#             */
/*   Updated: 2022/03/01 04:31:34 by gudias           ###   ########.fr       */
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

typedef struct	s_chunk_helper {
	t_stack	*stack;
	int	size;
	int	pivot;
	int	mid2;
	int	big_chunk;
	int	small_chunk;
	int	sub_chunk;

}		t_chunk_helper;

t_chunk_helper	*init_chunk_helper(t_stack *stack, int chunksize);

int	check_args(char **argv);

void	free_stack(t_stack *stack);
t_stack	*init_stack(char **values, char id);

int	stack_size(t_stack *stack);

t_bool	is_sorted_a(t_elem *chunk_start, int chunksize);
t_bool	is_sorted_b(t_elem *chunk_start, int chunksize);
t_bool	is_sorted_bot(t_elem *chunk_start, int chunksize);


t_bool	is_sorted(t_elem *chunk_start, t_elem *chunk_end);
t_bool	is_rev_sorted(t_elem *chunk_start, t_elem *chunk_end);
int	chunk_size(t_stack *stack, t_elem *chunk_end);
//
int	chunk_size_rev(t_stack *stack, t_elem *chunk_end);

//RM
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

//
void	sort(t_stack *stack_a, t_stack *stack_b, t_elem *chunk_end);

void	compare_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_3_bot(t_stack *stack_a, t_stack *stack_b);
void	sort_3_bot_b(t_stack *stack_a, t_stack *stack_b);

void	sort_handler_a(t_stack *stack_a, t_stack *stack_b, int chunksize);
void	sort_handler_a_bot(t_stack *stack_a, t_stack *stack_b, int chunksize);
void	sort_handler_b(t_stack *stack_a, t_stack *stack_b, int chunksize);
void	sort_handler_b_bot(t_stack *stack_a, t_stack *stack_b, int chunksize);
void	quicksort_next(t_stack *stack_a, t_stack *stack_b, t_chunk_helper *chunk_helper, t_bool rev);

int	calc_mid_pivot(t_stack *stack, int chunksize, t_bool rev);
int	calc_small_pivot(t_stack *stack, int chunksize, int median, t_bool rev);
int	calc_big_pivot(t_stack *stack, int chunksize, int median, t_bool rev);

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, int chunksize);
void	quicksort_a_rev(t_stack *stack_a, t_stack *stack_b, int chunksize);
void	quicksort_b(t_stack *stack_a, t_stack *stack_b, int chunksize);
void	quicksort_b_rev(t_stack *stack_a, t_stack *stack_b, int chunksize);

/*
void	quicksort_a(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);
void	quicksort_a_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);
void	quicksort_b(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);
void	quicksort_b_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot);
*/
void	swap_stack(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *dst_stack, t_stack *src_stack);
void	rotate_stack(t_stack *stack);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_stack(t_stack *stack);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif
