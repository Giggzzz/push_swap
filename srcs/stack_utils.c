/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:18:33 by gudias            #+#    #+#             */
/*   Updated: 2022/01/21 06:15:53 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*fill_stack(t_stack *stack, char **values)
{
	t_elem	*newelem;

		stack->bot = malloc (sizeof (t_elem));
		stack->bot->value = ft_atoi(*values);
		stack->bot->prev = NULL;
		stack->bot->next = NULL;
		stack->top = stack->bot;
		values++;
	while (*values)
	{
		newelem = malloc (sizeof (t_elem));
		if (!newelem)
			return (NULL);
		newelem->value = ft_atoi(*values);
		newelem->prev = NULL;
		newelem->next = stack->top;
		stack->top->prev = newelem;
		stack->top = newelem;
		values++;
	}
	return (stack);
}

t_stack	*init_stack(char **values)
{
	t_stack	*stack;

	stack = malloc (sizeof (t_stack));
	if (!stack)
		return (NULL);
	if (values)
		stack = fill_stack(stack, values);
	else
	{
		stack->bot = NULL;
		stack->top = NULL;
	}
	return (stack);
}



