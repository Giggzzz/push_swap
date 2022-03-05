/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:55:39 by gudias            #+#    #+#             */
/*   Updated: 2022/03/05 05:47:00 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_a, t_chunk_helper *chunk_helper)
{
	if (chunk_helper->size > 6 && stack_a->top->value < chunk_helper->mid2)
	{
		chunk_helper->sub_chunk++;
		if (stack_a->top != stack_a->bot)
			rotate_stack(stack_a);
	}
	else
		chunk_helper->big_chunk++;
}

void	quicksort_b_rev(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	t_chunk_helper	*chunk_helper;
	int				curr_size;

	chunk_helper = init_chunk_helper(stack_b, chunksize, TRUE);
	curr_size = chunksize;
	while (curr_size--)
	{
		reverse_rotate_stack(stack_b);
		if (stack_b->top->value >= chunk_helper->pivot)
		{
			push(stack_a, stack_b);
			subdivide(stack_a, chunk_helper);
		}
		else
			chunk_helper->small_chunk++;
	}
	quicksort_next(stack_a, stack_b, chunk_helper);
}	
