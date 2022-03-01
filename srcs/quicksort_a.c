/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/03/01 05:24:24 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_a, t_stack *stack_b, int *curr_size, t_chunk_helper *chunk_helper)
{
	if (*curr_size  > 0 && chunk_helper->size > 5 && stack_b->top->value < chunk_helper->mid2 && stack_a->top->value >= chunk_helper->pivot)
	{
		rotate_both(stack_a, stack_b);
		chunk_helper->big_chunk++;
		chunk_helper->small_chunk++;
		(*curr_size)--;
	}
	else if (chunk_helper->size > 5 && stack_b->top->value < chunk_helper->mid2)
	{
		if (stack_b->top != stack_b->bot)
			rotate_stack(stack_b);
		chunk_helper->small_chunk++;
	}
	else
		chunk_helper->sub_chunk++;
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	t_chunk_helper	*chunk_helper;
	int		curr_size;

	chunk_helper = init_chunk_helper(stack_a, chunksize);
	chunk_helper->pivot = calc_mid_pivot(stack_a, chunksize, FALSE);
	chunk_helper->mid2 = calc_small_pivot(stack_a, chunksize, chunk_helper->pivot, FALSE);
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
	quicksort_next(stack_a, stack_b, chunk_helper, FALSE);
}
