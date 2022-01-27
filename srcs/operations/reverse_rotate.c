/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:10:40 by gudias            #+#    #+#             */
/*   Updated: 2022/01/26 21:18:42 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_elem *elem;

	if (!stack->top || !stack->bot || !stack->bot->prev)
		return;
	elem = stack->bot;
	stack->bot = elem->prev;
	stack->bot->next = NULL;
	stack->top->prev = elem;
	elem->next = stack->top;
	elem->prev = NULL;
	stack->top = elem;
}

void	reverse_rotate_stack(t_stack *stack)
{
	reverse_rotate(stack);
	if (stack->id == 'A')
		ft_putendl("rra");
	else
		ft_putendl("rrb");
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl("rrr");
}
