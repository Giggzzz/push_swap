/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:07:34 by gudias            #+#    #+#             */
/*   Updated: 2022/02/17 04:33:14 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack *dst_stack, t_stack *src_stack)
{
	t_elem	*elem;

	if (!src_stack->top)
		return ;
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
}
