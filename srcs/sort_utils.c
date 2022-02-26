/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:43:31 by gudias            #+#    #+#             */
/*   Updated: 2022/02/26 03:25:23 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_mid_pivot(t_stack *stack, int chunk_size, t_bool rev)
{
	long long	total;
	int		size;
	t_elem		*ptr;

	if (!rev)
		ptr = stack->top;
	else
		ptr = stack->bot;
	total = 0;
	size = chunk_size;
	while (size--)
	{	
		//ft_printf("size: %d, val: %d\n", size, ptr->value);
		//print_stacks(stack, stack);
		total += ptr->value;
		if (!rev)
			ptr = ptr->next;
		else
			ptr = ptr->prev;
	}
	return (total / chunk_size);
}

int	calc_small_pivot(t_stack *stack, int chunk_size, int median, t_bool rev)
{
	long long	total;
	int		count;
	t_elem		*ptr;

	if (!rev)
		ptr = stack->top;
	else
		ptr = stack->bot;
	total = 0;
	count = 0;
	while (chunk_size--)
	{
		if (ptr->value < median)
		{
			total += ptr->value;
			count++;
		}
		if (!rev)
			ptr = ptr->next;
		else
			ptr = ptr->prev;
	}
	if (!count)
		return (0);
	return (total / count);
}

int	calc_big_pivot(t_stack *stack, int chunk_size, int median, t_bool rev)
{
	long long	total;
	int		count;
	t_elem		*ptr;
	
	if (!rev)
		ptr = stack->top;
	else
		ptr = stack->bot;
	total = 0;
	count = 0;
	while (chunk_size--)
	{
		if (ptr->value >= median)
		{
			total += ptr->value;
			count++;
		}
		if (!rev)
			ptr = ptr->next;
		else
			ptr = ptr->prev;
	}
	if (!count)
		return (0);
	return (total / count);
}
