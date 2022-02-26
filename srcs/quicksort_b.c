/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:55:39 by gudias            #+#    #+#             */
/*   Updated: 2022/02/26 03:21:58 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_a, t_stack *stack_b, int *size, int chunksize, int *small_chunk, int *big_chunk, int *big_small_chunk, int median, int mid2)
{
	if (*size  > 0 && chunksize > 6 && stack_a->top->value < mid2 && stack_b->top->value < median)
	{
		rotate_both(stack_a, stack_b);
		(*small_chunk)++;
		(*big_small_chunk)++;
		(*size)--;
	}
	else if (chunksize > 6 && stack_a->top->value < mid2)
	{
		if (stack_a->top != stack_a->bot)
			rotate_stack(stack_a);
		(*big_small_chunk)++;
	}
	else
		(*big_chunk)++;
}

void	quicksort_b(t_stack *stack_a, t_stack *stack_b, int chunksize)
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

	median = calc_mid_pivot(stack_b, size, FALSE);
	big_median = calc_big_pivot(stack_b, size, median, FALSE);

	while (size--)
	{
		if (stack_b->top->value >= median)
		{
			push(stack_a, stack_b);
			subdivide(stack_a, stack_b, &size, chunksize, &small_chunk, &big_chunk, &big_small_chunk, median, big_median);
		}
		else
		{
			rotate_stack(stack_b);
			small_chunk++;
		}
	}
	if (big_chunk)
		sort_handler_a(stack_a, stack_b, big_chunk);
	if (big_small_chunk)
		sort_handler_a_bot(stack_a, stack_b, big_small_chunk);
	if (small_chunk)
		sort_handler_b_bot(stack_a, stack_b, small_chunk);
}
