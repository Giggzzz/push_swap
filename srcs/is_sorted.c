/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:56:30 by gudias            #+#    #+#             */
/*   Updated: 2022/03/03 13:56:45 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted_a(t_elem *chunk_start, int chunksize)
{
	t_elem	*ptr;

	ptr = chunk_start;
	while (chunksize-- > 1)
	{
		if (ptr->value > ptr->next->value)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

t_bool	is_sorted_b(t_elem *chunk_start, int chunksize)
{
	t_elem	*ptr;

	ptr = chunk_start;
	while (chunksize-- > 1)
	{
		if (ptr->value < ptr->next->value)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

t_bool	is_sorted_bot(t_elem *chunk_start, int chunksize)
{
	t_elem	*ptr;

	ptr = chunk_start;
	while (chunksize-- > 1)
	{
		if (ptr->value < ptr->prev->value)
			return (FALSE);
		ptr = ptr->prev;
	}
	return (TRUE);
}
