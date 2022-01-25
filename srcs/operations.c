/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:53:40 by gudias            #+#    #+#             */
/*   Updated: 2022/01/25 04:28:23 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack->top || !stack->top->next)
		return;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	if (stack->id == 'A')
		ft_putstr("sa ");
	else
		ft_putstr("sb ");
}

void	push(t_stack *dst_stack, t_stack *src_stack)
{
	t_elem	*elem;

	if (!src_stack->top)
		return;
	elem = src_stack->top;
	if (elem->next)
	{
		src_stack->top = elem->next;
		src_stack->top->prev = NULL;
	}
	else
	{
		src_stack->top = NULL;
		src_stack->bot = NULL;
	}
	if (dst_stack->top)
		dst_stack->top->prev = elem;
	else
		dst_stack->bot = elem;
	elem->next = dst_stack->top;
	dst_stack->top = elem;
	if (dst_stack->id == 'A')
		ft_putstr("pa ");
	else
		ft_putstr("pb ");
}

void	rotate(t_stack *stack)
{
	t_elem	*elem;

	if (!stack->top || !stack->bot || !stack->top->next)
		return;
	elem = stack->top;
	stack->top = elem->next;
	stack->top->prev = NULL;
	stack->bot->next = elem;
	elem->prev = stack->bot;
	elem->next = NULL;
	stack->bot = elem;
	if (stack->id == 'A')
		ft_putstr("ra ");
	else
		ft_putstr("rb ");
}

void	reverse_rotate(t_stack *stack)
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
	if (stack->id == 'A')
		ft_putstr("rra ");
	else
		ft_putstr("rrb ");
}
