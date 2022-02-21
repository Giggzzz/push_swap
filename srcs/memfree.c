/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:43:30 by gudias            #+#    #+#             */
/*   Updated: 2022/02/21 08:50:05 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_elem	*ptr;
	t_elem	*tmp;

	ptr = stack->top;
	while (ptr)
	{
		tmp = ptr->next;
		free (ptr);
		ptr = tmp;
	}
	free(stack);
}
