/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:55:39 by gudias            #+#    #+#             */
/*   Updated: 2022/03/01 05:11:20 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_b, t_chunk_helper *chunk_helper)
{
	if (chunk_helper->size > 5 && stack_b->top->value < chunk_helper->mid2)
	{
		chunk_helper->small_chunk++;
		if (stack_b->top != stack_b->bot)
			rotate_stack(stack_b);
	}
	else 
		chunk_helper->sub_chunk++;
}

void	quicksort_a_rev(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	t_chunk_helper *chunk_helper;
	int		curr_size;

	chunk_helper = init_chunk_helper(stack_a, chunksize);
	curr_size = chunksize;
	
	chunk_helper->pivot = calc_mid_pivot(stack_a, chunksize, TRUE);
	chunk_helper->mid2 = calc_small_pivot(stack_a, chunksize, chunk_helper->pivot, TRUE);
	
	while (curr_size--)
	{	
		reverse_rotate_stack(stack_a);		
	
		if (stack_a->top->value < chunk_helper->pivot)
		{
			push(stack_b, stack_a);
			subdivide(stack_b, chunk_helper);
		}
		else
			chunk_helper->big_chunk++;
	}
	quicksort_next(stack_a, stack_b, chunk_helper, TRUE);
}	
