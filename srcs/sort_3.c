/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:41:10 by gudias            #+#    #+#             */
/*   Updated: 2022/02/11 21:51:48 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_max_down(t_stack *stack)
{
	rotate_stack(stack);
	swap_stack(stack);
	reverse_rotate_stack(stack);
}

static t_elem	*find_max(t_stack *stack)
{
	t_elem	*max;

	max = stack->top->next->next;
	if (stack->top->value > stack->top->next->value)
	{
		if (stack->top->value > max->value)
			max = stack->top;
	}
	else if (stack->top->next->value > max->value)
		max = stack->top->next;
	return (max);
}

void	sort_3(t_stack *stack)
{
	t_elem	*max;

	max = find_max(stack);
	if (max == stack->top)
	{
		if (stack->top->next->next != stack->bot)
		{
			swap_stack(stack);
			move_max_down(stack);
		}
		else
			rotate_stack(stack);
	}
	else if (max == stack->top->next)
	{
		if (stack->top->next->next != stack->bot)
			move_max_down(stack);
		else
			reverse_rotate_stack(stack);
	}
	compare_2(stack);
}

void	compare_2(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	if (stack->top->value > stack->top->next->value)
		swap_stack(stack);
}
