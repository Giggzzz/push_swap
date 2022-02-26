/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:55:39 by gudias            #+#    #+#             */
/*   Updated: 2022/02/26 03:29:22 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_a, int chunksize, int *big_chunk, int *big_small_chunk, int mid2)
{
	if (chunksize > 6 && stack_a->top->value < mid2)
	{
		(*big_small_chunk)++;
		if (stack_a->top != stack_a->bot)
			rotate_stack(stack_a);
	}
	else
		(*big_chunk)++;
}

void	quicksort_b_rev(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	int	small_chunk;
	int	big_chunk;
	int	big_small_chunk;
	int	median;
	int	big_median;
	int	size;

	small_chunk = 0;
	big_chunk = 0;
	big_small_chunk = 0;
	size = chunksize;

	median = calc_mid_pivot(stack_b, size, TRUE);
	big_median = calc_big_pivot(stack_b, size, median, TRUE); 

	while (size--)
	{
		reverse_rotate_stack(stack_b);

		if (stack_b->top->value >= median)
		{
			push(stack_a, stack_b);
			subdivide(stack_a, chunksize, &big_chunk, &big_small_chunk, big_median);
		}
		else
			small_chunk++;
	}

	if (big_chunk)
		sort_handler_a(stack_a, stack_b, big_chunk);
	if (big_small_chunk)
		sort_handler_a_bot(stack_a, stack_b, big_small_chunk);
	if (small_chunk)
		sort_handler_b(stack_a, stack_b, small_chunk);
}	
