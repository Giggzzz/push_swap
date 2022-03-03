/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/03/03 13:58:18 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_handler_a(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	if (chunksize == 2)
		compare_2(stack_a);
	else if (chunksize == 3)
		sort_3(stack_a);
	else if (!is_sorted_a(stack_a->top, chunksize) && chunksize > 0)
		quicksort_a(stack_a, stack_b, chunksize);
}

void	sort_handler_a_bot(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	if (stack_size(stack_a) == chunksize)
		sort_handler_a(stack_a, stack_b, chunksize);
	else if (chunksize == 2)
	{
		reverse_rotate_stack(stack_a);
		reverse_rotate_stack(stack_a);
		compare_2(stack_a);
	}
	else if (chunksize == 3)
		sort_3_bot(stack_a, stack_b);
	else if (is_sorted_bot(stack_a->bot, chunksize))
	{
		while (chunksize--)
			reverse_rotate_stack(stack_a);
	}
	else if (chunksize > 0)
		quicksort_a_rev(stack_a, stack_b, chunksize);
}

void	sort_handler_b(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	if (chunksize == 2)
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
		compare_2(stack_a);
	}
	else if (is_sorted_b(stack_b->top, chunksize))
	{
		while (chunksize--)
			push(stack_a, stack_b);
	}	
	else if (chunksize > 0)
		quicksort_b(stack_a, stack_b, chunksize);
}

void	sort_handler_b_bot(t_stack *stack_a, t_stack *stack_b, int chunksize)
{
	if (stack_size(stack_b) == chunksize)
		sort_handler_b(stack_a, stack_b, chunksize);
	else if (is_sorted_bot(stack_b->bot, chunksize))
	{
		while (chunksize--)
		{
			reverse_rotate_stack(stack_b);
			push(stack_a, stack_b);
		}
	}
	else if (chunksize > 0)
		quicksort_b_rev(stack_a, stack_b, chunksize);
}

void	quicksort_next(t_stack *stack_a, t_stack *stack_b, t_chunk_helper *chunk_helper, t_bool rev)
{
	if (chunk_helper->stack->id == 'A' && !rev)
		sort_handler_a_bot(stack_a, stack_b, chunk_helper->big_chunk);
	else
		sort_handler_a(stack_a, stack_b, chunk_helper->big_chunk);
	if (chunk_helper->stack->id == 'A')
		sort_handler_b(stack_a, stack_b, chunk_helper->sub_chunk);
	else
		sort_handler_a_bot(stack_a, stack_b, chunk_helper->sub_chunk);
	if (chunk_helper->stack->id != 'A' && rev)
		sort_handler_b(stack_a, stack_b, chunk_helper->small_chunk);
	else
		sort_handler_b_bot(stack_a, stack_b, chunk_helper->small_chunk);
	free (chunk_helper);
}
