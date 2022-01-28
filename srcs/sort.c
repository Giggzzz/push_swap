/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/01/28 07:49:01 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_stack *stack)
{
	t_elem	*ptr;

	ptr = stack->top;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, t_elem *pivot)
{
	t_elem	*small_pivot;
	t_elem	*big_pivot;

	small_pivot = NULL;
	big_pivot = NULL;
	if (stack_a->top->next == pivot)
	{
		if (stack_a->top->value > pivot->value)
			swap_stack(stack_a);
	}
	else
	{
		while (stack_a->top != pivot)
		{
			if (stack_a->top->value < pivot->value)
			{
				if (small_pivot == NULL)
					small_pivot = stack_a->top;
				push(stack_b, stack_a);
			}
			else
			{
				if (big_pivot == NULL)
					big_pivot = stack_a->top;
				rotate_stack(stack_a);
			}
		}
		if (big_pivot != NULL)
		{
			push(stack_b, stack_a);
			quicksort_a_rev(stack_a, stack_b, big_pivot);
			push(stack_a, stack_b);
		}
		if (small_pivot != NULL)
			quicksort_b(stack_a, stack_b, small_pivot);
	}
}

void	quicksort_a_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot)
{
	t_elem	*small_pivot;
	t_elem	*big_pivot;

	small_pivot = NULL;
	big_pivot = NULL;
	
	if (stack_a->top == pivot && pivot->next)
	{
		rotate_stack(stack_a);
		quicksort_a(stack_a, stack_b, pivot);
	}
	else if (stack_a->top != pivot)
	{
		reverse_rotate_stack(stack_a);		
		while (stack_a->top != pivot)
		{
			if (stack_a->top->value < pivot->value)
			{
				if (small_pivot == NULL)
					small_pivot = stack_a->top;
				push(stack_b, stack_a);
			}
			else
				if (big_pivot == NULL)
					big_pivot = stack_a->top;
			reverse_rotate_stack(stack_a);
		}
		if (big_pivot != NULL)
		{
			push(stack_a, stack_b);
			quicksort_a(stack_a, stack_b, big_pivot);
			push(stack_b, stack_a);
		}
		if (small_pivot != NULL)
			quicksort_b(stack_a, stack_b, small_pivot);
	}	
}

void	quicksort_b(t_stack *stack_a, t_stack *stack_b, t_elem *pivot)
{
	t_elem	*small_pivot;
	t_elem	*big_pivot;

	small_pivot = NULL;
	big_pivot = NULL;
	if (stack_b->top->next == pivot)
	{
		if (stack_b->top->value < pivot->value)
			swap_stack(stack_b);
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
	else
	{
		while (stack_b->top != pivot)
		{
			if (stack_b->top->value > pivot->value)
			{
				if (big_pivot == NULL)
					big_pivot = stack_b->top;
				push(stack_a, stack_b);
			}
			else
			{
				if (small_pivot == NULL)
					small_pivot = stack_b->top;
				rotate_stack(stack_b);
			}
		}
		if (big_pivot != NULL)
			quicksort_a(stack_a, stack_b, big_pivot);
		push(stack_a, stack_b);
		if (small_pivot != NULL)
			quicksort_b_rev(stack_a, stack_b, small_pivot);
	}
}

void	quicksort_b_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot)
{
	t_elem	*small_pivot;
	t_elem	*big_pivot;

	small_pivot = NULL;
	big_pivot = NULL;
	if (stack_b->top == pivot && pivot->next)
	{
		rotate_stack(stack_b);
		quicksort_b(stack_a, stack_b, pivot);
	}
	else if (stack_b->top != pivot)
	{
		reverse_rotate_stack(stack_b);		
		while (stack_b->top != pivot)
		{
			if (stack_b->top->value > pivot->value)
			{
				if (big_pivot == NULL)
					big_pivot = stack_b->top;
				push(stack_a, stack_b);
			}
			else
				if (small_pivot == NULL)
					small_pivot = stack_b->top;
			reverse_rotate_stack(stack_b);
		}
		if (big_pivot != NULL)
			quicksort_a(stack_a, stack_b, big_pivot);
		push(stack_a, stack_b);	
		if (small_pivot != NULL)
			quicksort_b(stack_a, stack_b, small_pivot);
	}	
}

/*void dummy_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	ops;

	ops = 0;
	while (!is_sorted(stack_a))
	{
		while (stack_a->top != NULL && stack_a->top != stack_a->bot)
		{
			while (stack_a->top->next && stack_a->top->value < stack_a->top->next->value)
			{
				push(stack_b, stack_a);
				ops++;
			}
			swap_stack(stack_a);
			ops++;
			push(stack_b, stack_a);
			ops++;
		}
		while (stack_b->top != NULL && stack_b->top != stack_b->bot)
		{
			while (stack_b->top->next && stack_b->top->value > stack_b->top->next->value)
			{
				push(stack_a, stack_b);
				ops++;
			}
			swap_stack(stack_b);
			ops++;
			push(stack_a, stack_b);
			ops++;
		}
	}
	ft_printf("\n\nStack sorted! Took: %d\n", ops);
}*/
