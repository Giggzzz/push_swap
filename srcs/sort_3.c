/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:41:10 by gudias            #+#    #+#             */
/*   Updated: 2022/03/01 05:35:41 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_max_down(t_stack *stack, t_elem *max)
{
	if (max == stack->top)
		swap_stack(stack);
	if (max != stack->top->next->next)
	{
		rotate_stack(stack);
		swap_stack(stack);
		reverse_rotate_stack(stack);
	}
}

static t_elem	*find_max(t_elem *max)
{
	if (max->next->value > max->next->next->value)
	{
		if (max->next->value > max->value)
			max = max->next;
	}
	else if (max->next->next->value > max->value)
		max = max->next->next;
	return (max);
}

void	sort_3(t_stack *stack)
{
	t_elem	*max;

	max = find_max(stack->top);
	if (stack->top->next->next != stack->bot)
		move_max_down(stack, max);
	else if (max == stack->top)
		rotate_stack(stack);
	else if (max == stack->top->next)
		reverse_rotate_stack(stack);
	compare_2(stack);
}

void	sort_3_bot(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*max;
	t_bool	pushed;

	pushed = 0;
	max = find_max(stack_a->bot->prev->prev);
	reverse_rotate_stack(stack_a);
	if (stack_a->bot->prev == max && stack_a->top < stack_a->bot)
	{
		push(stack_b, stack_a);
		pushed = 1;
	}
	reverse_rotate_stack(stack_a);
	if (stack_a->top == max)
		swap_stack(stack_a);
	else if (stack_a->bot == max && !pushed)
		push(stack_b, stack_a);
	reverse_rotate_stack(stack_a);
	if (stack_a->top == max)
	{
		swap_stack(stack_a);
		push(stack_a, stack_b);
	}
	compare_2(stack_a);
}

void	sort_3_bot_b(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*max;
	int	pushed;

	pushed = 0;
	max = find_max(stack_b->bot->prev->prev);
	reverse_rotate_stack(stack_b);
	if (stack_b->top == max)
	{
		push(stack_a, stack_b);
		pushed++;
	}
	reverse_rotate_stack(stack_b);
	if (stack_b->top == max)
	{
		push(stack_a, stack_b);
		pushed++;
	}
	if (pushed && stack_b->top > stack_b->bot)
	{
		push(stack_a, stack_b);
		pushed++;
	}
	reverse_rotate_stack(stack_b);
	while (pushed++ < 3)
		push(stack_a, stack_b);
}

void	compare_2(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	if (stack->top->value > stack->top->next->value)
		swap_stack(stack);
}
