/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/01/25 04:12:22 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_stack *stack_a)
{
	t_elem	*ptr;

	ptr = stack_a->top;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

void sort(t_stack *stack_a, t_stack *stack_b)
{

	while (!is_sorted(stack_a))
	{
		while (stack_a->top != NULL && stack_a->top != stack_a->bot)
		{
			while (stack_a->top->next && stack_a->top->value < stack_a->top->next->value)
				push(stack_b, stack_a);
			swap(stack_a);
			push(stack_b, stack_a);
		}
		while (stack_b->top != NULL && stack_b->top != stack_b->bot)
		{
			while (stack_b->top->next && stack_b->top->value > stack_b->top->next->value)
				push(stack_a, stack_b);
			swap(stack_b);
			push(stack_a, stack_b);
		}
	}
}
