/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/02/26 03:22:42 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_a, t_stack *stack_b, int *size, int chunksize, int *small_chunk, int *big_chunk, int *small_small_chunk, int median, int mid2)
{
	if (*size  > 0 && chunksize > 5 && stack_b->top->value < mid2 && stack_a->top->value >= median)
	{
		rotate_both(stack_a, stack_b);
		(*big_chunk)++;
		(*small_small_chunk)++;
		(*size)--;
	}
	else if (chunksize > 5 && stack_b->top->value < mid2)
	{
		if (stack_b->top != stack_b->bot)
			rotate_stack(stack_b);
		(*small_small_chunk)++;
	}
	else
		(*small_chunk)++;
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	int	small_chunk;
	int	big_chunk;
	int	small_small_chunk;
	int	median;
	int	small_median;
	int	size;

	small_chunk = 0;
	big_chunk = 0;
	small_small_chunk = 0;
	size = chunksize;

	median = calc_mid_pivot(stack_a, size, FALSE);
	small_median = calc_small_pivot(stack_a, size, median, FALSE);

	while(size--)
	{
		if (stack_a->top->value < median)
		{
			push(stack_b, stack_a);
			subdivide(stack_a, stack_b, &size, chunksize, &small_chunk, &big_chunk, &small_small_chunk, median, small_median);
		}
		else
		{
			rotate_stack(stack_a);
			big_chunk++;
		}
	}
	if (big_chunk)
		sort_handler_a_bot(stack_a, stack_b, big_chunk);
	if (small_chunk)
		sort_handler_b(stack_a, stack_b, small_chunk);
	if (small_small_chunk)
		sort_handler_b_bot(stack_a, stack_b, small_small_chunk);
}




