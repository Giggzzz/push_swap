/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:55:39 by gudias            #+#    #+#             */
/*   Updated: 2022/03/01 05:22:48 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_a, t_stack *stack_b, int *curr_size, t_chunk_helper *chunk_helper)
{
	if (*curr_size  > 0 && chunk_helper->size > 6 && stack_a->top->value < chunk_helper->mid2 && stack_b->top->value < chunk_helper->pivot)
	{
		rotate_both(stack_a, stack_b);
		chunk_helper->small_chunk++;
		chunk_helper->sub_chunk++;
		(*curr_size)--;
	}
	else if (chunk_helper->size > 6 && stack_a->top->value < chunk_helper->mid2)
	{
		if (stack_a->top != stack_a->bot)
			rotate_stack(stack_a);
		chunk_helper->sub_chunk++;
	}
	else
		chunk_helper->big_chunk++;
}

void	quicksort_b(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	t_chunk_helper	*chunk_helper;
	int		curr_size;

	chunk_helper = init_chunk_helper(stack_b, chunksize);
	curr_size = chunksize;
	chunk_helper->pivot = calc_mid_pivot(stack_b, chunksize, FALSE);
	chunk_helper->mid2 = calc_big_pivot(stack_b, chunksize, chunk_helper->pivot, FALSE);

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
	quicksort_next(stack_a, stack_b, chunk_helper, FALSE);
}
