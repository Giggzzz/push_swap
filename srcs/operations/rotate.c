/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:10:03 by gudias            #+#    #+#             */
/*   Updated: 2022/01/28 07:52:46 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_elem	*elem;

	if (!stack->top || !stack->bot || stack->top == stack->bot)
		return;
	elem = stack->top;
	stack->top = elem->next;
	stack->top->prev = NULL;
	stack->bot->next = elem;
	elem->prev = stack->bot;
	elem->next = NULL;
	stack->bot = elem;
}

void	rotate_stack(t_stack *stack)
{
	rotate(stack);
	if (stack->id == 'A')
		ft_putendl("ra");
	else
		ft_putendl("rb");
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl("rr");
}
