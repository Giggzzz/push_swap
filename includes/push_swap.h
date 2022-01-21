/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:45 by gudias            #+#    #+#             */
/*   Updated: 2022/01/21 07:33:14 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_elem {
	int		value;
	struct s_elem	*prev;
	struct s_elem	*next;
}		t_elem;

typedef struct s_stack {
	t_elem	*top;
	t_elem	*bot;
}		t_stack;

int	check_args(char **argv);
t_stack	*init_stack(char **values);


void	swap(t_stack *stack);
void	push(t_stack *dst_stack, t_stack *src_stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif
