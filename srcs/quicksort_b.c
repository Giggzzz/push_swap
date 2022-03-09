/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:55:39 by gudias            #+#    #+#             */
/*   Updated: 2022/03/09 16:20:30 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *a, t_stack *b, int *size, t_chunk_helper *chunk)
{
	if (chunk->size > 6 && a->top->value < chunk->mid2)
	{
		if (*size > 0 && b->top->value < chunk->pivot)
		{
			rotate_both(a, b);
			chunk->small_chunk++;
			(*size)--;
		}
		else
		{
			if (a->top != a->bot)
				rotate_stack(a);
		}
		chunk->mid_chunk++;
	}
	else
		chunk->big_chunk++;
}

void	quicksort_b(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	t_chunk_helper	*chunk_helper;
	int				curr_size;

	chunk_helper = init_chunk_helper(stack_b, chunksize, FALSE);
	curr_size = chunksize;
	while (curr_size--)
	{
		if (stack_b->top->value >= chunk_helper->pivot)
		{
			push(stack_a, stack_b);
			subdivide(stack_a, stack_b, &curr_size, chunk_helper);
		}
		else
		{
			rotate_stack(stack_b);
			chunk_helper->small_chunk++;
		}
	}
	quicksort_next(stack_a, stack_b, chunk_helper);
}
