/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:10:03 by gudias            #+#    #+#             */
/*   Updated: 2022/02/17 04:33:27 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack *stack)
{
	t_elem	*elem;

	if (!stack->top || !stack->bot || stack->top == stack->bot)
		return ;
	elem = stack->top;
	stack->top = elem->next;
	stack->top->prev = NULL;
	stack->bot->next = elem;
	elem->prev = stack->bot;
	elem->next = NULL;
	stack->bot = elem;
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
