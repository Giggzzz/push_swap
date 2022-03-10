/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:42:49 by gudias            #+#    #+#             */
/*   Updated: 2022/03/10 12:55:54 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	err_quit(void)
{
	ft_putendl("Error");
	exit(0);
}

static void	do_operation(char *ops, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(ops, "sa\n", 3))
		swap(stack_a);
	else if (!ft_strncmp(ops, "sb\n", 3))
		swap(stack_b);
	else if (!ft_strncmp(ops, "ss\n", 3))
		swap_both(stack_a, stack_b);
	else if (!ft_strncmp(ops, "pa\n", 3))
		push(stack_a, stack_b);
	else if (!ft_strncmp(ops, "pb\n", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(ops, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(ops, "rb\n", 3))
		rotate(stack_b);
	else if (!ft_strncmp(ops, "rr\n", 3))
		rotate_both(stack_a, stack_b);
	else if (!ft_strncmp(ops, "rra\n", 4))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(ops, "rrb\n", 4))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(ops, "rrr\n", 4))
		reverse_rotate_both(stack_a, stack_b);
	else
		err_quit();
}

static void	try_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*ops;

	ops = get_next_line(0);
	while (ops)
	{
		do_operation(ops, stack_a, stack_b);
		ops = get_next_line(0);
	}
}

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
		try_sort(stack_a, stack_b);
		if (is_sorted(stack_a->top, stack_a->bot) && !stack_b->top)
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	return (0);
}
