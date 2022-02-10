/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:41:10 by gudias            #+#    #+#             */
/*   Updated: 2022/02/10 04:46:51 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	if (!stack->top->next || stack->top->next != stack->bot->prev)
		return ;
	if (stack->top->value > stack->bot->value && stack->top->value > stack->top->next->value)
		rotate_stack(stack);
	else if (stack->top->next->value > stack->top->value && stack->top->next->value > stack->bot->value)
		reverse_rotate_stack(stack);

	if (stack->top->value > stack->top->next->value)
			swap_stack(stack);
}

//todo:
//sort 3 not alone in stack
