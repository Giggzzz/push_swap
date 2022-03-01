/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:25:35 by gudias            #+#    #+#             */
/*   Updated: 2022/03/01 05:25:18 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk_helper	*init_chunk_helper(t_stack *stack, int chunksize)
{
	t_chunk_helper	*chunk_helper;

	chunk_helper = malloc (sizeof (t_chunk_helper));
	if (!chunk_helper)
		return (NULL);	
	chunk_helper->stack = stack;
	chunk_helper->size = chunksize;
	chunk_helper->big_chunk = 0;
	chunk_helper->small_chunk = 0;
	chunk_helper->sub_chunk = 0;
	return (chunk_helper);
}
