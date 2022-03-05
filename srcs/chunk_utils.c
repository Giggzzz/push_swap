/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:25:35 by gudias            #+#    #+#             */
/*   Updated: 2022/03/05 05:44:34 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk_helper	*init_chunk_helper(t_stack *stack, int chunksize, t_bool rev)
{
	t_chunk_helper	*chunk;

	chunk = malloc (sizeof (t_chunk_helper));
	if (!chunk)
		return (NULL);
	chunk->stack = stack;
	chunk->rev = rev;
	chunk->size = chunksize;
	chunk->big_chunk = 0;
	chunk->small_chunk = 0;
	chunk->sub_chunk = 0;
	chunk->pivot = calc_mid_pivot(stack, chunksize, rev);
	if (stack->id == 'A')
		chunk->mid2 = calc_small_pivot(stack, chunksize, chunk->pivot, rev);
	else
		chunk->mid2 = calc_big_pivot(stack, chunksize, chunk->pivot, rev);
	return (chunk);
}
