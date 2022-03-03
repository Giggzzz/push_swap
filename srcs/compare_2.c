/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:46:11 by gudias            #+#    #+#             */
/*   Updated: 2022/03/03 12:46:55 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_2(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	if (stack->top->value > stack->top->next->value)
		swap_stack(stack);
}
