/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:45 by gudias            #+#    #+#             */
/*   Updated: 2022/03/03 12:37:19 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include<stdlib.h>
# include "../../libft/includes/libft.h"

typedef struct s_elem {
	int		value;
	struct s_elem	*prev;
	struct s_elem	*next;
}		t_elem;

typedef struct s_stack {
	char	id;
	t_elem	*top;
	t_elem	*bot;
}		t_stack;

int	check_args(char **argv);
t_stack	*init_stack(char **values, char id);
t_bool	is_sorted(t_elem *chunk_start, t_elem *chunk_end);
void	swap(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *dst_stack, t_stack *src_stack);
void	rotate(t_stack *stack);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif
