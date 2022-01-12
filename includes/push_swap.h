/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:45 by gudias            #+#    #+#             */
/*   Updated: 2022/01/12 02:27:10 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int	size;
}	t_stack;
	
void	swap(int* stack);
void	push(int* stack);
void	rotate(int* stack);
void	reverse_rotate(int* stack);

#endif
