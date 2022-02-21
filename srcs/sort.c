/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:38:10 by gudias            #+#    #+#             */
/*   Updated: 2022/02/21 08:23:27 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_pivot(t_stack *stack, t_elem *chunk_limit, t_bool rev)
{
	long long	pivot;
	int		elem_count;
	t_elem		*ptr;

	if (!rev)
		ptr = stack->top;
	else
		ptr = stack->bot;
	pivot = chunk_limit->value;
	elem_count = 1;
	while (ptr != chunk_limit)
	{
		pivot += ptr->value;
		elem_count++;
		if (!rev)
			ptr = ptr->next;
		else
			ptr = ptr->prev;
	}
	return (pivot / elem_count);
}

int	calc_mid2(t_stack *stack, int chunk_size, int median, t_bool rev)
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

int	calc_pivot2(t_stack *stack, int chunk_size, t_bool rev)
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
	while (chunk_size-- > 0)
	{
		total += ptr->value;
		if (!rev)
			ptr = ptr->next;
		else
			ptr = ptr->prev;
	}
	return (total / size);
}

void	partition(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	median;
	int	small_chunk;
	int	big_chunk;
	
	small_chunk = 0;
	big_chunk = 0;
	median = calc_pivot2(stack_a, chunk_size, FALSE);
	while (chunk_size-- > 0)
	{
		if (stack_a->top->value < median)
		{
			push(stack_b, stack_a);
			small_chunk++;
		}
		else
		{
			rotate_stack(stack_a);
			big_chunk++;
		}
	}
	//quicksort_a_rev(stack_a, stack_b, big_chunk);
	//quicksort_b(stack_a, stack_b, small_chunk);
}

void	sort(t_stack *stack_a, t_stack *stack_b, t_elem *chunk_end)
{
	int	chunksize;

	chunksize = chunk_size(stack_a, chunk_end);
	if (chunksize == 2)
		compare_2(stack_a);
	else if (chunksize == 3)
		sort_3(stack_a);
	else if (!is_sorted(stack_a->top, chunk_end))
	{
		//partition(stack_a, stack_b, chunksize);
		quicksort_a(stack_a, stack_b, chunk_end);
	}
	
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, t_elem *chunk_end)
{
	t_elem	*small_chunk;
	t_elem	*big_chunk;
	t_elem	*small_small_chunk;
	int	median;

	small_chunk = NULL;
	big_chunk = NULL;
	small_small_chunk = NULL;

	int 	size = chunk_size(stack_a, chunk_end);
	int	chunksize;
	chunksize = size;
	int mid2;
		median = calc_pivot(stack_a, chunk_end, FALSE);
	mid2 = calc_mid2(stack_a, size, median, FALSE);
		//while (stack_a->top != chunk_end)
		while(size--)
		{
			if (stack_a->top->value < median)
			{
				//if (!small_chunk)
				//	small_chunk = stack_a->top;
				push(stack_b, stack_a);
				//
				if (size  > 0 && chunksize > 5 && stack_b->top->value < mid2 && stack_a->top->value >= median)
				{
					//ft_putendl("yes");
					if (!big_chunk)
						big_chunk = stack_a->top;
					if (!small_small_chunk)
						small_small_chunk = stack_b->top;
					rotate_both(stack_a, stack_b);
					//rotate_stack(stack_a);
					//rotate_stack(stack_b);	
					size--;
				}
				else if (chunksize > 5 && stack_b->top->value < mid2)
				{
					//ft_putendl("ok2");
					if (!small_small_chunk)
						small_small_chunk = stack_b->top;
					if (stack_b->top != stack_b->bot)
						rotate_stack(stack_b);
				}
				else if (!small_chunk)
					small_chunk = stack_b->top;
				///
			}
			else
			{
				if (!big_chunk)
					big_chunk = stack_a->top;
				rotate_stack(stack_a);
			}
		}
		//if (big_chunk)
			quicksort_a_rev(stack_a, stack_b, big_chunk);
		if (small_chunk)
			quicksort_b(stack_a, stack_b, small_chunk);
		if (small_small_chunk)
			quicksort_b_rev(stack_a, stack_b, small_small_chunk);
}

void	quicksort_a_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot)
{
	t_elem	*small_pivot;
	t_elem	*big_pivot;
	t_elem	*small_small_chunk;
	int	median;
	int	mid2;

	int 	size = chunk_size_rev(stack_a, pivot);
	int	chunksize;
	chunksize = size;

	small_pivot = NULL;
	big_pivot = NULL;
	small_small_chunk = NULL;
	
	if (stack_a->top == pivot) //si chunk seul dans stack
	{
		if (pivot->next) //si chunk > 1
			sort(stack_a, stack_b, stack_a->bot);
			//quicksort_a(stack_a, stack_b, stack_a->bot);
	}
	else if (pivot->next == stack_a->bot) //si chunk = 2
	{
		reverse_rotate_stack(stack_a);
		reverse_rotate_stack(stack_a);
		compare_2(stack_a);
	}
	else if (is_sorted(pivot, stack_a->bot)) //si trié
	{	
		while (stack_a->top != pivot)
			reverse_rotate_stack(stack_a);
	}
	else
	{
		median = calc_pivot(stack_a, pivot, TRUE);
		mid2 = calc_mid2(stack_a, size, median, TRUE);
		reverse_rotate_stack(stack_a);		
		while (stack_a->top != pivot)
		{
			if (stack_a->top->value < median)
			{
				//if (small_pivot == NULL)
				//	small_pivot = stack_a->top;
				push(stack_b, stack_a);
				if (chunksize > 5 && stack_b->top->value < mid2)
				{
					//ft_putendl("ok2");
					if (!small_small_chunk)
						small_small_chunk = stack_b->top;
					if (stack_b->top != stack_b->bot)
						rotate_stack(stack_b);
				}
				else if (!small_pivot)
					small_pivot = stack_b->top;
				///
			}
			else
				if (big_pivot == NULL)
					big_pivot = stack_a->top;
			reverse_rotate_stack(stack_a);
		}
		if (stack_a->top->value < median)
		{
			push(stack_b, stack_a);
			if (chunksize > 5 && stack_b->top->value < mid2)
			{
				//ft_putendl("ok2");
				if (!small_small_chunk)
					small_small_chunk = stack_b->top;
				if (stack_b->top != stack_b->bot)
					rotate_stack(stack_b);
			}
			else if (!small_pivot)
				small_pivot = stack_b->top;
		}

		if (big_pivot != NULL)
		{
		//	push(stack_a, stack_b);
			sort(stack_a, stack_b, big_pivot);
			//quicksort_a(stack_a, stack_b, big_pivot);
		//	push(stack_b, stack_a);
		}
		if (small_pivot != NULL)
			quicksort_b(stack_a, stack_b, small_pivot);
		if (small_small_chunk)
			quicksort_b_rev(stack_a, stack_b, small_small_chunk);
	}	
}

void	quicksort_b(t_stack *stack_a, t_stack *stack_b, t_elem *pivot)
{
	t_elem	*small_pivot;
	t_elem	*big_pivot;
	t_elem	*big_small_chunk;
	int	median;

	small_pivot = NULL;
	big_pivot = NULL;
	big_small_chunk = NULL;

	int	size = chunk_size(stack_b, pivot);
	int	chunksize;
	chunksize = size;
	int	mid2;
	
	if (is_rev_sorted(stack_b->top, pivot))
	{
		while (size--)
			push(stack_a, stack_b);
	}
	else if (stack_b->top->next == pivot)
	{
		if (stack_b->top->value < pivot->value)
			swap_stack(stack_b);
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
	else
	{
		median = calc_pivot(stack_b, pivot, FALSE);
		mid2 = calc_big_pivot(stack_b, size, median, FALSE);
		while (stack_b->top != pivot)
		{
			if (stack_b->top->value >= median)
			{
				//if (big_pivot == NULL)
				//	big_pivot = stack_b->top;
				push(stack_a, stack_b);
				//
				if (size  > 0 && chunksize > 100 && stack_a->top->value < mid2 && stack_b->top->value < median)
				{
					//ft_putendl("yes");
					if (!small_pivot)
						small_pivot = stack_b->top;
					if (!big_small_chunk)
						big_small_chunk = stack_a->top;
					rotate_both(stack_a, stack_b);
					//rotate_stack(stack_a);
					//rotate_stack(stack_b);	
					size--;
				}
				else if (chunksize > 100 && stack_a->top->value < mid2)
				{
					//ft_putendl("ok2");
					if (!big_small_chunk)
						big_small_chunk = stack_a->top;
					if (stack_a->top != stack_a->bot)
						rotate_stack(stack_a);
				}
				else if (!big_pivot)
					big_pivot = stack_a->top;
				//
			}
			else
			{
				if (small_pivot == NULL)
					small_pivot = stack_b->top;
				rotate_stack(stack_b);
			}
			size--;
		}
		if (stack_b->top->value >= median)
		{
			push(stack_a, stack_b);
			if (chunksize > 100 && stack_a->top->value < mid2)
			{
				//ft_putendl("ok2");
				if (!big_small_chunk)
					big_small_chunk = stack_a->top;
				if (stack_a->top != stack_a->bot)
					rotate_stack(stack_a);
			}
			else if (!big_pivot)
				big_pivot = stack_a->top;
		}
		else
		{
			if (small_pivot == NULL)
				small_pivot = stack_b->top;
			rotate_stack(stack_b);
		}
		if (big_pivot != NULL)
			sort(stack_a, stack_b, big_pivot);
			//quicksort_a(stack_a, stack_b, big_pivot);
		if (big_small_chunk)
			quicksort_a_rev(stack_a, stack_b, big_small_chunk);
		//push(stack_a, stack_b);
		if (small_pivot != NULL)
			quicksort_b_rev(stack_a, stack_b, small_pivot);
	}
}

void	quicksort_b_rev(t_stack *stack_a, t_stack *stack_b, t_elem *pivot)
{
	t_elem	*small_pivot;
	t_elem	*big_pivot;
	t_elem	*big_small_chunk;
	int	median;
	int	mid2;

	int	size = chunk_size_rev(stack_b, pivot);
	int	chunksize;
	chunksize = size;

	small_pivot = NULL;
	big_pivot = NULL;
	big_small_chunk = NULL;
	
	if (stack_b->top == pivot)
	{
		quicksort_b(stack_a, stack_b, stack_b->bot);
	}
	else if (stack_b->top != pivot)
	{	
		median = calc_pivot(stack_b, pivot, TRUE);
		mid2 = calc_big_pivot(stack_b, size, median, TRUE); 
		reverse_rotate_stack(stack_b);		
		while (stack_b->top != pivot)
		{
			if (stack_b->top->value >= median)
			{
				//if (big_pivot == NULL)
				//	big_pivot = stack_b->top;
				push(stack_a, stack_b);
				if (chunksize > 6 && stack_a->top->value < mid2)
				{
					//ft_putendl("ok2");
					if (!big_small_chunk)
						big_small_chunk = stack_a->top;
					if (stack_a->top != stack_a->bot)
						rotate_stack(stack_a);
				}
				else if (!big_pivot)
					big_pivot = stack_a->top;
			}
			else if (small_pivot == NULL)
				small_pivot = stack_b->top;
			reverse_rotate_stack(stack_b);
		}
		if (stack_b->top->value >= median)
		{
			push(stack_a, stack_b);
			if (chunksize > 6 && stack_a->top->value < mid2)
			{
				//ft_putendl("ok2");
				if (!big_small_chunk)
					big_small_chunk = stack_a->top;
				if (stack_a->top != stack_a->bot)
					rotate_stack(stack_a);
			}
			else if (!big_pivot)
				big_pivot = stack_a->top;
		}
		else
			if (small_pivot == NULL)
				small_pivot = stack_b->top;

		if (big_pivot != NULL)
			sort(stack_a, stack_b, big_pivot);
			//quicksort_a(stack_a, stack_b, big_pivot);
		if (big_small_chunk)
			quicksort_a_rev(stack_a, stack_b, big_small_chunk);
		//push(stack_a, stack_b);	
		if (small_pivot != NULL)
			quicksort_b(stack_a, stack_b, small_pivot);
	}	
}


/*RM
void dummy_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_sorted(stack_a))
	{
		while (stack_a->top != NULL && stack_a->top != stack_a->bot)
		{
			while (stack_a->top->next && stack_a->top->value < stack_a->top->next->value)
			{
				push(stack_b, stack_a);
			}
			swap_stack(stack_a);
			push(stack_b, stack_a);
		}
		while (stack_b->top != NULL && stack_b->top != stack_b->bot)
		{
			while (stack_b->top->next && stack_b->top->value > stack_b->top->next->value)
			{
				push(stack_a, stack_b);
			}
			swap_stack(stack_b);
			push(stack_a, stack_b);
		}
	}
}*/
