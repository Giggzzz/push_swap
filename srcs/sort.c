/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/01/27 06:45:44 by gudias           ###   ########.fr       */
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

void dummy_sort(t_stack *stack_a, t_stack *stack_b)
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
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*pivot;

	pivot = stack_a->top;
	rotate_stack(stack_a);
	while (stack_a->top != pivot)
	{
	//	print_stacks(stack_a, stack_b);
		if (stack_a->top->value < pivot->value)
			push(stack_b, stack_a);
		else
			rotate_stack(stack_a);
	}
	push(stack_b, stack_a);
	if (stack_a->top != NULL && stack_a->top->next)
	{
		quick_sort(stack_a, stack_b);
		quick_sort_rev(stack_a, stack_b);
	}
}

void	quick_sort_rev(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*pivot;

	pivot = stack_b->top;
	rotate_stack(stack_b);
	while (stack_b->top != pivot)
	{
		if (stack_b->top->value > pivot->value)
			push(stack_a, stack_b);
		else
			rotate_stack(stack_b);
	}
	push(stack_a, stack_b);
	if (stack_b->top != NULL && stack_b->top->next)
	{
		quick_sort_rev(stack_a, stack_b);
		quick_sort(stack_a, stack_b);
	}
}
