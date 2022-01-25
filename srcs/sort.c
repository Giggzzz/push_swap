/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/01/25 21:04:43 by gudias           ###   ########.fr       */
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
			swap(stack_a);
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
			swap(stack_b);
			ops++;
			push(stack_a, stack_b);
			ops++;
		}
	}
	ft_printf("\n\nStack sorted! Took: %d\n", ops);
}
