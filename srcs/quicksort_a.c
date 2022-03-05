/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/03/05 05:46:27 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *a, t_stack *b, int *size, t_chunk_helper *chunk)
{
	if (chunk->size > 5 && b->top->value < chunk->mid2)
	{
		if (*size > 0 && a->top->value >= chunk->pivot)
		{
			rotate_both(a, b);
			chunk->big_chunk++;
			(*size)--;
		}
		else
		{
			if (b->top != b->bot)
				rotate_stack(b);
		}
		chunk->small_chunk++;
	}
	else
		chunk->sub_chunk++;
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	t_chunk_helper	*chunk_helper;
	int				curr_size;

	chunk_helper = init_chunk_helper(stack_a, chunksize, FALSE);
	curr_size = chunksize;
	while (curr_size--)
	{
		if (stack_a->top->value < chunk_helper->pivot)
		{
			push(stack_b, stack_a);
			subdivide(stack_a, stack_b, &curr_size, chunk_helper);
		}
		else
		{
			rotate_stack(stack_a);
			chunk_helper->big_chunk++;
		}
	}
	quicksort_next(stack_a, stack_b, chunk_helper);
}
