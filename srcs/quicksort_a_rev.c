/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:55:39 by gudias            #+#    #+#             */
/*   Updated: 2022/02/25 22:06:21 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	subdivide(t_stack *stack_b, int chunksize, int *small_chunk, int *small_small_chunk, int mid2)
{
	if (chunksize > 5 && stack_b->top->value < mid2)
	{
		(*small_small_chunk)++;
		if (stack_b->top != stack_b->bot)
			rotate_stack(stack_b);
	}
	else 
		(*small_chunk)++;
}

void	quicksort_a_rev(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	int	small_chunk;
	int	big_chunk;
	int	small_small_chunk;
	int	median;
	int	small_median;
	int 	size;

	small_chunk = 0;
	big_chunk = 0;
	small_small_chunk = 0;
	size = chunksize;
	
	median = calc_mid_pivot(stack_a, size, TRUE);
	small_median = calc_small_pivot(stack_a, size, median, TRUE);
	
	while (size--)
	{	
		reverse_rotate_stack(stack_a);		
	
		if (stack_a->top->value < median)
		{
			push(stack_b, stack_a);
			subdivide(stack_b, chunksize, &small_chunk, &small_small_chunk, small_median);
		}
		else
			big_chunk++;
	}

	if (big_chunk)
		sort_handler_a(stack_a, stack_b, big_chunk);
	if (small_chunk)
		sort_handler_b(stack_a, stack_b, small_chunk);
	if (small_small_chunk)
		sort_handler_b_bot(stack_a, stack_b, small_small_chunk);
}	
