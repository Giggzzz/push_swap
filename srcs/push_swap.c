/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:09 by gudias            #+#    #+#             */
/*   Updated: 2022/01/21 08:10:08 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 2)
	{
		argv++;
		if (!check_args(argv))
			return (0);
		stack_a = init_stack(argv);
		stack_b = init_stack(NULL);
		if (!stack_a || !stack_b)
			ft_putendl("init stack error");
		else
		{
			t_elem *elem_a = stack_a->top;
			t_elem *elem_b = stack_b->top;
			ft_printf("\nA\n");
			while (elem_a)
			{
				ft_printf("%d\n", elem_a->value);
				elem_a = elem_a->next;
			}
			ft_printf("\nB\n");
			while (elem_b)
			{
				ft_printf("%d\n", elem_b->value);
				elem_b = elem_b->next;
			}
			push(stack_b, stack_a);
			rotate(stack_a);
			push(stack_b, stack_a);
			elem_a = stack_a->top;
			elem_b = stack_b->top;
			ft_printf("\nA\n");
			while (elem_a)
			{
				ft_printf("%d\n", elem_a->value);
				elem_a = elem_a->next;
			}
			ft_printf("\nB\n");
			while (elem_b)
			{
				ft_printf("%d\n", elem_b->value);
				elem_b = elem_b->next;
			}
			reverse_rotate(stack_a);
			reverse_rotate(stack_a);
			push(stack_a, stack_b);
			elem_a = stack_a->top;
			elem_b = stack_b->top;
			ft_printf("\nA\n");
			while (elem_a)
			{
				ft_printf("%d\n", elem_a->value);
				elem_a = elem_a->next;
			}
			ft_printf("\nB\n");
			while (elem_b)
			{
				ft_printf("%d\n", elem_b->value);
				elem_b = elem_b->next;
			}
		}	
	}
	else
		ft_putstr_fd("Bad args nb\n", 1);
	return (0);
}
