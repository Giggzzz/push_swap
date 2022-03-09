/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:18:33 by gudias            #+#    #+#             */
/*   Updated: 2022/03/09 18:23:48 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_size(t_stack *stack)
{
	int		size;
	t_elem	*ptr;

	if (!stack)
		return (0);
	size = 0;
	ptr = stack->top;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
/*
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_elem *elem_a;
	t_elem *elem_b;

	elem_a = stack_a->top;
	elem_b = stack_b->top;
	ft_printf("\n\tA\t\t\tB\n");
	ft_printf("-----------------\t-----------------\n");
	while (elem_a || elem_b)
	{
		if (elem_a)
			ft_printf("   %d\t\t\t", elem_a->value);
		else
			ft_printf("\t\t\t");
		if (elem_b)
			ft_printf("   %d\n", elem_b->value);
		else
			ft_printf("\n");
		if (elem_a)
			elem_a = elem_a->next;
		if (elem_b)
			elem_b = elem_b->next;
	}
	ft_printf("\n");
}*/
