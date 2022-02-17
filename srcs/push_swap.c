/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:09 by gudias            #+#    #+#             */
/*   Updated: 2022/02/17 19:29:46 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		argv++;
		if (ft_strchr(*argv, ' '))
			argv = ft_split(*argv, ' ');
		if (!check_args(argv))
			return (0);
		stack_a = init_stack(argv, 'A');
		stack_b = init_stack(NULL, 'B');
		if (!stack_a || !stack_b)
			ft_putendl("Error");
		else
		{
			sort(stack_a, stack_b, stack_a->bot);
		//	print_stacks(stack_a, stack_b);
		}	
	}
	return (0);
}
