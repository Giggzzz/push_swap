/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:18:33 by gudias            #+#    #+#             */
/*   Updated: 2022/02/17 04:32:22 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*fill_stack(t_stack *stack, char **values)
{
	t_elem	*newelem;

	stack->bot = malloc (sizeof (t_elem));
	if (!stack->bot)
		return (NULL);
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
		newelem->prev = stack->bot;
		newelem->next = NULL;
		stack->bot->next = newelem;
		stack->bot = newelem;
		values++;
	}
	return (stack);
}

t_stack	*init_stack(char **values, char id)
{
	t_stack	*stack;

	stack = malloc (sizeof (t_stack));
	if (!stack)
		return (NULL);
	stack->id = id;
	if (values)
		stack = fill_stack(stack, values);
	else
	{
		stack->bot = NULL;
		stack->top = NULL;
	}
	return (stack);
}

t_bool	is_sorted(t_elem *chunk_start, t_elem *chunk_end)
{
	t_elem	*ptr;

	ptr = chunk_start;
	while (ptr->next && ptr != chunk_end)
	{
		if (ptr->value > ptr->next->value)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}
